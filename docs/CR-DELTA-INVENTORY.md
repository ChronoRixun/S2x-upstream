# CR delta inventory against current upstream

Audit: 2026-10-14, upstream `26358ffa5091427705a416ef62472ad793bdaf68`. Fork: `codex/s2x-cr-upstream-rebuild`, native base `0048253`. The fork release preserves its tested base; contribution proposals begin at current upstream.

## Isolated proposals

The landing page lists six focused branches: console log paths, bounded chat events, guarded Gun Game costumes, bounded MP bot fill, safe CSV tables and explicit AppData isolation. No CR prices/rewards, custom-name pools, Manager branding or companion-bot native/gameplay code is imported into them.

Bot fill declares the existing multiplayer script-program-buffer pointer (`0xB12A070`) used by its stock spawn helper. This dependency was caught by the first Debug build and is included in that branch. The address is inherited from the reviewed CR implementation. The CSV branch carries production-helper tests for quoted input, invalid quotes, blank rows, padded-table rejection before allocation, safe asset paths, engine hash behavior and cache keys for distinct/case-folded mod paths.

Combined Debug/Release builds and those helper tests pass. Combined compilation is not independent native runtime certification. Live mod switches, real-client chat, listen-server spawning, delayed spawn/level cancellation and Gun Game costume transitions remain submission checks. Allocation is stubbed only for the oversized-table refusal test. No PR was submitted to Brent's repository.

## Larger reusable candidates requiring focused extraction

| Source | Candidate mechanics | Boundary |
| --- | --- | --- |
| `gsc/script_extension.*`, `script_storage.hpp`, `script_loading.cpp` | Scoped file storage, bounded script/chat/client/roster/notice APIs and lifecycle handling. | Separate ABI/storage/scheduler decisions from CR reward/event consumers. |
| `dedicated_party*`, `party.*` | One-shot scripted next-map handoff, hosted score-limit synchronization and lifecycle cleanup. | Preserve operator precedence; prove each protocol/lifecycle change separately. |
| `server_admin*`, `server_admin_notice.gsc` | Optional local Manager-owned administration with fresh targets and bot/host guards. | Larger optional tooling proposal, outside the six small branches. |
| `tools/ServerManager`, host launcher/status tools | Host UI, administration and status compatibility. | Optional project not shipped upstream; branding, themes and presets require separate interest/scope. |
| Marketplace/order persistence | Replay, rollback, duplicate-grant and readiness correctness where a stock failure reproduces. | Do not present the policy-heavy CR economy restoration as one proven upstream bug fix. |

## Fork policy excluded

CR catalogs/offers, acquisition routes, reward quantities, prices, bundles, loot weights and progression payouts stay in the fork. So do legacy CR migration, custom bot names, rotation presets, branding and update defaults/pruning policy. Experimental companion-bot/native/navmesh research and sealed bot kits are excluded from this contribution repository and the fork-only GitHub release. Logs, local runtimes, ownership tokens, retail files and real saves are never contribution payload.

## Historical/merged work

Player-limit dvars match upstream 219f678 / PR 90 exactly, patch ID fa702be34ef12500e0e793e5a2d735fd022df6d8. Lobby slot bounds/null-client protection are semantically present at 710f61f; do not replay the overlapping old 0x19A59 hook over upstream's 0x19A66 implementation. A local historical console-log-path-2 patch duplicates the first console patch; the new v2 uses modern atomic ownership.

## Upstream additions missing from the older fork base

The mod manager (f83d7b7) and muzzle-flash toggle (26358ff) arrived after the fork's tested base. Missing files/menu edits for those are base lag, not CR additions. CSV cache keys now distinguish the resolved mod path because frontend mount/unmount restarts LUI without necessarily unloading a map.

## File index of CR additions/modifications

Each path below is an index for inspection, not permission to copy the entire file upstream. A file may mix reusable mechanics with fork policy. Upstream-only files absent from the older fork base are excluded.
```text
M	.github/workflows/build.yml
M	.gitignore
M	README.md
A	data/scripts/mp/s2x_gungame_bots.gsc
A	data/scripts/mp/s2x_server_events.gsc
M	data/ui_scripts/mp/find_match/s2x_findgame_menu.lua
M	data/ui_scripts/mp/patches/unlocks.lua
A	docs/CR-ECONOMY-MIGRATION.md
A	docs/CR-ECONOMY-RESTORATION.md
A	docs/RELEASE-v1.7.0-rc1.md
A	docs/UPSTREAM-CONTRIBUTION-NOTES.md
A	docs/UPSTREAM-ECONOMY-COMPARISON.md
A	docs/UPSTREAM-REBUILD-VALIDATION.md
M	src/client/component/bots.cpp
M	src/client/component/command.cpp
M	src/client/component/console/console.cpp
M	src/client/component/dedicated_party.cpp
M	src/client/component/dedicated_party_client.cpp
A	src/client/component/demonware/cr_progression.cpp
A	src/client/component/demonware/cr_progression.hpp
A	src/client/component/demonware/cr_progression_policy.hpp
M	src/client/component/demonware/economy.cpp
M	src/client/component/demonware/runtime.cpp
M	src/client/component/demonware/zombies_progression.cpp
M	src/client/component/gsc/script_extension.cpp
M	src/client/component/gsc/script_extension.hpp
M	src/client/component/gsc/script_loading.cpp
A	src/client/component/gsc/script_storage.hpp
M	src/client/component/master_server.cpp
M	src/client/component/party.cpp
M	src/client/component/party.hpp
A	src/client/component/server_admin.cpp
A	src/client/component/server_admin.hpp
A	src/client/component/server_admin_pipe.hpp
A	src/client/component/server_admin_policy.hpp
A	src/client/component/stringtable_override.cpp
M	src/client/component/updater.cpp
M	src/client/game/demonware/achievement/order_progress.cpp
M	src/client/game/demonware/achievement/orders.cpp
M	src/client/game/demonware/achievement/store.cpp
M	src/client/game/demonware/loot/policy.cpp
M	src/client/game/demonware/marketplace/catalog.cpp
A	src/client/game/demonware/marketplace/cr_catalog.hpp
M	src/client/game/demonware/marketplace/cwl.hpp
M	src/client/game/demonware/marketplace/purchase.cpp
M	src/client/game/demonware/runtime_context.hpp
M	src/client/game/game.cpp
M	src/client/game/symbols.hpp
M	src/client/launcher/launcher.cpp
M	src/client/resource.hpp
M	src/client/resource.rc
M	src/client/resources/dw/achievement_offers.json
M	src/client/resources/dw/publisher_variables/mp_tu26_1_20.json
M	src/client/resources/launcher/launcher.rml
A	src/client/resources/server_admin_notice.gsc
M	src/client/updater/file_updater.cpp
A	tests/client-economy/README.md
A	tests/client-economy/mp-rank-probe.lua
A	tests/client-economy/mp-shop-probe.lua
A	tests/client-economy/zm-inventory-probe.lua
A	tests/client-economy/zm-match-observer.lua
A	tests/client-economy/zm-rank-probe.lua
A	tests/cr-catalog/PARITY.md
A	tests/cr-catalog/README.md
A	tests/cr-catalog/catalog.py
A	tests/cr-catalog/claims.cpp
A	tests/cr-catalog/claims.vcxproj
A	tests/cr-catalog/crypto.cpp
A	tests/cr-catalog/shim/std_include.hpp
A	tests/cr-catalog/shim/utils/cryptography.hpp
A	tests/cr-loot/policy.py
A	tests/economy-loader/loader.cpp
A	tests/economy-loader/loader.vcxproj
A	tests/economy-loader/shim/std_include.hpp
A	tests/economy-migration/test_migration.py
A	tests/next-map/TESTING.md
A	tests/next-map/cfg-probe.cfg
A	tests/next-map/native.py
A	tests/next-map/nextmap-test.cfg
A	tests/next-map/nextmap_probe.gsc
A	tests/progression/README.md
A	tests/progression/policy.cpp
A	tests/scripting/README.md
A	tests/scripting/appdata.py
A	tests/scripting/chat.py
A	tests/scripting/native.gsc
A	tests/scripting/status.ps1
A	tests/scripting/storage.cpp
A	tests/scripting/storage.vcxproj
A	tests/server-admin/README.md
A	tests/server-admin/native_policy_pipe.cpp
A	tests/server-manager/ADMIN-NOTICES.md
A	tests/server-manager/AdminPipeFixture.cs
A	tests/server-manager/BrowserUiTests.cs
A	tests/server-manager/CARD-ORDER.md
A	tests/server-manager/MasterBrowserTests.cs
A	tests/server-manager/README.md
A	tests/server-manager/SurvivalProfileTests.cs
A	tests/server-manager/WindowLeakTests.cs
A	tests/server-manager/admin-notice-probe.gsc
A	tests/server-manager/admin.ps1
A	tests/server-manager/autobalance.ps1
A	tests/server-manager/card-drag.ps1
A	tests/server-manager/card-order.ps1
A	tests/server-manager/layout-fit.ps1
A	tests/server-manager/run.ps1
A	tests/server-manager/server-scripts.ps1
A	tests/server-manager/themes.ps1
A	tools/ServerLauncher.xaml
A	tools/ServerManager/.gitignore
A	tools/ServerManager/ADMINISTRATION.md
A	tools/ServerManager/App.xaml
A	tools/ServerManager/App.xaml.cs
A	tools/ServerManager/Assets/Fonts/BarlowCondensed-Bold.ttf
A	tools/ServerManager/Assets/Fonts/BarlowCondensed-Regular.ttf
A	tools/ServerManager/Assets/Fonts/BarlowCondensed-SemiBold.ttf
A	tools/ServerManager/Assets/Fonts/BlackOpsOne-Regular.ttf
A	tools/ServerManager/Assets/Fonts/ChakraPetch-Regular.ttf
A	tools/ServerManager/Assets/Fonts/ChakraPetch-SemiBold.ttf
A	tools/ServerManager/Assets/Fonts/Cinzel-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/Creepster-Regular.ttf
A	tools/ServerManager/Assets/Fonts/IBMPlexMono-Regular.ttf
A	tools/ServerManager/Assets/Fonts/JetBrainsMono-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/Manrope-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/Orbitron-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/Oswald-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/PixelifySans-VariableFont_wght.ttf
A	tools/ServerManager/Assets/Fonts/PressStart2P-Regular.ttf
A	tools/ServerManager/Assets/Fonts/README.md
A	tools/ServerManager/Assets/Fonts/Rajdhani-Bold.ttf
A	tools/ServerManager/Assets/Fonts/Rajdhani-Medium.ttf
A	tools/ServerManager/Assets/Fonts/RussoOne-Regular.ttf
A	tools/ServerManager/Assets/Fonts/ShareTechMono-Regular.ttf
A	tools/ServerManager/Assets/Fonts/SpaceMono-Bold.ttf
A	tools/ServerManager/Assets/Fonts/SpaceMono-Regular.ttf
A	tools/ServerManager/Assets/Fonts/SpecialElite-Regular.ttf
A	tools/ServerManager/Assets/Fonts/VT323-Regular.ttf
A	tools/ServerManager/Assets/Fonts/licenses/BarlowCondensed-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/BlackOpsOne-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/ChakraPetch-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/Cinzel-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/Creepster-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/IBMPlexMono-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/JetBrainsMono-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/Manrope-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/Orbitron-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/Oswald-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/PixelifySans-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/PressStart2P-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/README.md
A	tools/ServerManager/Assets/Fonts/licenses/Rajdhani-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/RussoOne-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/ShareTechMono-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/SpaceMono-OFL.txt
A	tools/ServerManager/Assets/Fonts/licenses/SpecialElite-LICENSE.txt
A	tools/ServerManager/Assets/Fonts/licenses/VT323-OFL.txt
A	tools/ServerManager/Assets/S2xServerManager.ico
A	tools/ServerManager/Assets/make-icon.ps1
A	tools/ServerManager/MainWindow.xaml
A	tools/ServerManager/MainWindow.xaml.cs
A	tools/ServerManager/Models/GameData.cs
A	tools/ServerManager/Models/LaunchProfile.cs
A	tools/ServerManager/Models/MasterServerRow.cs
A	tools/ServerManager/Models/ServerPreset.cs
A	tools/ServerManager/Models/ServerState.cs
A	tools/ServerManager/README.md
A	tools/ServerManager/S2xServerManager.csproj
A	tools/ServerManager/ServerScripts/.gitattributes
A	tools/ServerManager/ServerScripts/s2x_autobalance.gsc
A	tools/ServerManager/ServerScripts/s2x_servercmds.gsc
A	tools/ServerManager/Services/CardOrderStore.cs
A	tools/ServerManager/Services/CfgText.cs
A	tools/ServerManager/Services/Css.cs
A	tools/ServerManager/Services/DemoData.cs
A	tools/ServerManager/Services/GameFolder.cs
A	tools/ServerManager/Services/LaunchProfiles.cs
A	tools/ServerManager/Services/LogTail.cs
A	tools/ServerManager/Services/ManagedServerOwnershipStore.cs
A	tools/ServerManager/Services/MasterBrowserClient.cs
A	tools/ServerManager/Services/Network.cs
A	tools/ServerManager/Services/PresetJson.cs
A	tools/ServerManager/Services/PresetStore.cs
A	tools/ServerManager/Services/ProcessInspector.cs
A	tools/ServerManager/Services/ServerAdminClient.cs
A	tools/ServerManager/Services/ServerController.cs
A	tools/ServerManager/Services/ServerQuery.cs
A	tools/ServerManager/Services/ServerScriptInstaller.cs
A	tools/ServerManager/Services/ThemeCatalog.cs
A	tools/ServerManager/Services/ThemeFonts.cs
A	tools/ServerManager/Services/ThemeManager.cs
A	tools/ServerManager/Services/ThemeResources.cs
A	tools/ServerManager/Services/ThemeSettings.cs
A	tools/ServerManager/Services/TrayIcon.cs
A	tools/ServerManager/Theme.xaml
A	tools/ServerManager/ViewModels/ConsoleViewModel.cs
A	tools/ServerManager/ViewModels/EditorViewModel.cs
A	tools/ServerManager/ViewModels/FleetViewModel.cs
A	tools/ServerManager/ViewModels/MasterBrowserViewModel.cs
A	tools/ServerManager/ViewModels/Observable.cs
A	tools/ServerManager/ViewModels/RotationRowViewModel.cs
A	tools/ServerManager/ViewModels/ServerCardViewModel.cs
A	tools/ServerManager/Views/AdminWindow.xaml
A	tools/ServerManager/Views/AdminWindow.xaml.cs
A	tools/ServerManager/Views/CardReorder.cs
A	tools/ServerManager/Views/ConfirmDialog.xaml
A	tools/ServerManager/Views/ConfirmDialog.xaml.cs
A	tools/ServerManager/Views/ConsoleDrawer.xaml
A	tools/ServerManager/Views/ConsoleDrawer.xaml.cs
A	tools/ServerManager/Views/DragReorder.cs
A	tools/ServerManager/Views/EditorView.xaml
A	tools/ServerManager/Views/EditorView.xaml.cs
A	tools/ServerManager/Views/FitPanels.cs
A	tools/ServerManager/Views/FleetView.xaml
A	tools/ServerManager/Views/FleetView.xaml.cs
A	tools/ServerManager/Views/LaunchProfilesDialog.xaml
A	tools/ServerManager/Views/LaunchProfilesDialog.xaml.cs
A	tools/ServerManager/Views/MasterBrowserWindow.xaml
A	tools/ServerManager/Views/MasterBrowserWindow.xaml.cs
A	tools/ServerManager/Views/NewServerDialog.xaml
A	tools/ServerManager/Views/NewServerDialog.xaml.cs
A	tools/ServerManager/Views/Palette.cs
A	tools/ServerManager/Views/PromptDialog.xaml
A	tools/ServerManager/Views/PromptDialog.xaml.cs
A	tools/ServerManager/Views/SettingsDialog.xaml
A	tools/ServerManager/Views/SettingsDialog.xaml.cs
A	tools/ServerManager/Views/TextEffects.cs
A	tools/ServerManager/Views/ThemeLayers.cs
A	tools/ServerManager/Views/ThemeVisuals.cs
A	tools/migrate-cr-economy.py
A	tools/server-launcher.cmd
A	tools/server-launcher.ps1
A	tools/server-presets/Ground War DLC.json
A	tools/server-presets/Shipment 24-7.json
A	tools/server-presets/Small Map Moshpit DLC.json
A	tools/server-presets/Small Map Moshpit.json
A	tools/server-presets/Standard Maps Mix.json
A	tools/server-scripts/README.md
A	tools/server-scripts/examples/scripting_api.gsc
A	tools/server-status.ps1
```

## Mod-loader integration boundaries

The new loader mounts selected roots and restarts LUI; it does not construct CSV StringTable assets or repair Gun Game loadouts. Current upstream only recognises roots containing scripts or ui_scripts, so CSV-only mod-folder recognition is not supplied by the CSV proposal. Use normal loose paths or an otherwise valid selected mod. The override's mod-path cache keys protect lookup identity, not automatic replacement of engine-held table pointers.

The Gun Game script can be delivered as a selected gameplay mod. Its mode/map guards do not resolve other scripts changing the same costumes/loadouts. Both proposal branches now carry these constraints and concrete enable/unload/reload/gameplay acceptance scenarios. They remain source/build-checked staging proposals pending native mod-manager runtime acceptance.
