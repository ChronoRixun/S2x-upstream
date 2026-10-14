# S2x upstream contributions

This repository stages focused proposals for [Brentdevent/S2x](https://github.com/Brentdevent/S2x). CR releases, economy policy and experimental companion-bot kits belong in [S2x CR](https://github.com/ChronoRixun/S2x-CR).

Refreshed **2026-10-14** against upstream **26358ffa5091427705a416ef62472ad793bdaf68**. `master` mirrors that upstream commit without fork changes. The default `readme` branch carries this landing page and the [delta inventory](docs/CR-DELTA-INVENTORY.md) alongside current upstream source. It is the documentation exception to one-feature-per-branch.

## Refreshed proposals

These are independent staging branches, not automatically submitted or merged upstream.

| Branch | Isolated change |
| --- | --- |
| [up/console-log-path-v2](https://github.com/ChronoRixun/S2x-upstream/tree/up/console-log-path-v2) | Immutable launch log path with modern worker-thread ownership. |
| [up/chat-notify-v2](https://github.com/ChronoRixun/S2x-upstream/tree/up/chat-notify-v2) | Owned, bounded player chat events after stock handling. |
| [up/gun-game-bot-costumes-v2](https://github.com/ChronoRixun/S2x-upstream/tree/up/gun-game-bot-costumes-v2) | Guarded Gun Game bot division costumes; loose script installed explicitly. |
| [up/dedicated-bot-fill-v2](https://github.com/ChronoRixun/S2x-upstream/tree/up/dedicated-bot-fill-v2) | Opt-in MP fill, owned-slot caps, bounded retries and level cancellation; no custom names or companions. |
| [up/stringtable-override-v2](https://github.com/ChronoRixun/S2x-upstream/tree/up/stringtable-override-v2) | Bounded loose CSV assets, stable storage and mounted-mod path cache keys. |
| [up/appdata-isolation-v1](https://github.com/ChronoRixun/S2x-upstream/tree/up/appdata-isolation-v1) | Absolute AppData root override for isolated instances. |

Combined current-upstream Debug/Release builds and production CSV tests pass. This is source/build validation, not individual native runtime certification. Real-client chat, mod switches, delayed spawns/level cancellation, listen servers and costume transitions still need focused acceptance before upstream submission. Prior CR runtime results came from its older tested 0048253 base.

## Historical branches

Old heads remain intact for provenance; use the refreshed branch when listed.

| Historical branch | Disposition |
| --- | --- |
| `up/dedicated-player-limit-dvars` | Exact change merged in [upstream PR 90](https://github.com/Brentdevent/S2x/pull/90); no duplicate proposal. |
| `up/lobby-party-slot-bound` | Equivalent bound/null-client guard already upstream at 710f61f. Do not replay the overlapping old hook. |
| `up/console-log-path` | Superseded by v2; old borrowed-Dvar approach is obsolete. |
| `up/chat-notify` | Superseded by v2's post-handler event and owned payload. |
| `up/gun-game-bot-costumes` | Superseded by the guarded v2 script. |
| `up/dedicated-bot-fill-2` | Historical playlist-bypass approach; modern bounded v2 is the current proposal. |
| `up/stringtable-override` | Superseded by the hardened parser/mod-path v2. |

No historical branch was deleted or force-rewritten. Larger script/hosting/admin APIs remain separately inventoried. CR prices, rewards, catalogs, migration, names, presets, branding and companion-bot kits stay fork policy unless upstream explicitly requests them.

For downloads/player support use [S2x CR releases](https://github.com/ChronoRixun/S2x-CR/releases) and its issues. This staging repository publishes source proposals, not CR client releases or a companion-bot kit.
