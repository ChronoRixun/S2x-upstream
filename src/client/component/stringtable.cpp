#include <std_include.hpp>
#include "loader/component_loader.hpp"

#include "filesystem.hpp"
#include "console/console.hpp"

#include "game/game.hpp"

#include <utils/hook.hpp>
#include <utils/memory.hpp>
#include <utils/string.hpp>

namespace stringtable
{
	namespace
	{
		utils::hook::detour db_find_x_asset_header_hook;

		// Loose tables by lower-case asset name; null when there is no loose file.
		// They are never freed: the game keeps pointers into a table once it has it.
		std::mutex tables_mutex;
		std::unordered_map<std::string, game::StringTable*> tables;

		// The game compares a cell's hash before its text when it looks a value up,
		// so cells are hashed the way it does (h * 31 + tolower(c)), or they are never found.
		int hash_cell(const char* text)
		{
			auto hash = 0u;
			for (; *text; ++text)
			{
				const auto c = static_cast<int>(static_cast<signed char>(*text));
				hash = hash * 31 + static_cast<unsigned int>(c >= 'A' && c <= 'Z' ? c + ('a' - 'A') : c);
			}

			return static_cast<int>(hash);
		}

		// A row per line and a cell per comma; a comma inside double quotes stays in its cell.
		game::StringTable* load_table(const std::string& name)
		{
			std::string data{};
			std::string path{};
			if (!filesystem::read_file(name, &data, &path))
			{
				return nullptr;
			}

			std::vector<std::vector<std::string>> rows(1);
			std::string cell{};
			auto quoted = false;

			for (std::size_t i = data.starts_with("\xEF\xBB\xBF") ? 3 : 0; i < data.size(); ++i)
			{
				const auto c = data[i];
				if (quoted && c == '"' && i + 1 < data.size() && data[i + 1] == '"')
				{
					cell += c;
					++i;
				}
				else if (c == '"')
				{
					quoted = !quoted;
				}
				else if (!quoted && (c == ',' || c == '\n'))
				{
					rows.back().emplace_back(std::move(cell));
					cell.clear();

					if (c == '\n')
					{
						rows.emplace_back();
					}
				}
				else if (c != '\r')
				{
					cell += c;
				}
			}

			if (!cell.empty() || !rows.back().empty())
			{
				rows.back().emplace_back(std::move(cell));
			}
			else
			{
				rows.pop_back();
			}

			if (rows.empty())
			{
				return nullptr;
			}

			std::size_t columns = 0;
			for (const auto& row : rows)
			{
				columns = std::max(columns, row.size());
			}

			auto* table = utils::memory::allocate<game::StringTable>();
			table->name = utils::memory::duplicate_string(name);
			table->rowCount = static_cast<int>(rows.size());
			table->columnCount = static_cast<int>(columns);
			table->values = utils::memory::allocate_array<game::StringTableCell>(rows.size() * columns);

			for (std::size_t row = 0; row < rows.size(); ++row)
			{
				for (std::size_t column = 0; column < columns; ++column)
				{
					auto& value = table->values[row * columns + column];
					value.string = utils::memory::duplicate_string(column < rows[row].size() ? rows[row][column] : "");
					value.hash = hash_cell(value.string);
				}
			}

			console::info("Loading string table '%s' from '%s'\n", name.data(), path.data());
			return table;
		}

		game::XAssetHeader db_find_x_asset_header_stub(const game::XAssetType type, const char* name,
			const int allow_create_default)
		{
			if (type == game::ASSET_TYPE_STRINGTABLE && name)
			{
				std::lock_guard _(tables_mutex);

				const auto [entry, inserted] = tables.try_emplace(utils::string::to_lower(name));
				if (inserted)
				{
					entry->second = load_table(name);
				}

				if (entry->second)
				{
					return { .stringTable = entry->second };
				}
			}

			return db_find_x_asset_header_hook.invoke<game::XAssetHeader>(type, name, allow_create_default);
		}
	}

	class component final : public generic_component
	{
	public:
		void post_unpack() override
		{
			db_find_x_asset_header_hook.create(game::DB_FindXAssetHeader, db_find_x_asset_header_stub);
		}
	};
}

REGISTER_COMPONENT(stringtable::component)
