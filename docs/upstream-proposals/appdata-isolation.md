# Isolated AppData root

Base: 26358ffa5091427705a416ef62472ad793bdaf68. Add `-appdata-dir <absolute directory>` to isolate loose files, mod data and caches for one instance. Reject relative paths and a missing value; normalize the chosen root. With no override, preserve the original LocalAppData/s2x behavior.

This is a root override, not player-save migration or a game-profile selector. Use a separate working/game directory or an explicit named profile as well. The implementation is the same override used in the isolated CR QA; it adds no CR economy or companion-bot component. Current-upstream build/runtime evidence is recorded in the contribution inventory.
