#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "game/game.hpp"

#include <utils/hook.hpp>

namespace lobby_client_slots
{
	namespace
	{
		// The lobby party pump at game+0x19940 walks all 48 members of the game party
		// and, for each present one, reads svs_clients[i].state at game+0x19A6D with
		// RSI = i * sizeof(client_t) (0x11E870) and no bound on i. Stock S2 gets away
		// with that because SV_Startup (game+0x6DCDB0) sizes svs_clients by sv_maxclients
		// and the dvar defaults to 48. The dedicated party sets sv_maxclients to
		// party_maxplayers (dedicated_party.cpp, apply_configured_party_limits), and its
		// host sits in party slot get_host_member_index(), past the end of that array on
		// every server. A four-player server crashed here reading slot 11: RSI = 0xC4FCD0,
		// 12.9 MB into a 4.7 MB array and 8.2 MB past its end.
		//
		// Bound the probe by sv_maxclients, and by svs_clients being allocated at all. A
		// party slot with no client slot behind it simply is not connected, which is the
		// same conclusion the stock read reaches for every state other than 1.
		constexpr auto probe_site = 0x19A59;
		constexpr auto probe_not_connected = 0x19A73;
		constexpr auto probe_next_member = 0x19AA1;
		constexpr auto sv_running_dvar = 0x1BD3778;

		void lobby_party_client_slot_probe(utils::hook::assembler& a)
		{
			const auto not_connected = a.new_label();
			const auto connected = a.new_label();

			// Replaced: the stock sv_running gate at 19A59.
			a.mov(rax, static_cast<std::uint64_t>(sv_running_dvar + game::get_base()));
			a.mov(rax, qword_ptr(rax));
			a.test(rax, rax);
			a.jz(not_connected);
			a.cmp(byte_ptr(rax, 0x10), 0);
			a.jz(not_connected);

			// Added: the party slot has to address an allocated client slot.
			a.mov(rax, reinterpret_cast<std::uint64_t>(game::sv_maxclients.get()));
			a.cmp(edi, dword_ptr(rax));
			a.jge(not_connected);

			a.mov(rax, reinterpret_cast<std::uint64_t>(game::mp::svs_clients.get()));
			a.mov(rax, qword_ptr(rax));
			a.test(rax, rax);
			a.jz(not_connected);

			// Replaced: CMP dword ptr [RSI + RAX],1 / JZ 19AA1.
			a.cmp(dword_ptr(rsi, rax), 1);
			a.jz(connected);

			a.bind(not_connected);
			a.mov(rax, static_cast<std::uint64_t>(probe_not_connected + game::get_base()));
			a.jmp(rax);

			a.bind(connected);
			a.mov(rax, static_cast<std::uint64_t>(probe_next_member + game::get_base()));
			a.jmp(rax);
		}
	}

	class component final : public multiplayer_component
	{
	public:
		void post_unpack() override
		{
			utils::hook::nop(probe_site + game::get_base(),
				probe_not_connected - probe_site);
			utils::hook::jump(probe_site + game::get_base(),
				utils::hook::assemble(lobby_party_client_slot_probe));
		}
	};
}

REGISTER_COMPONENT(lobby_client_slots::component)
