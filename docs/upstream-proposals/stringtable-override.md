# stringtable override

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Build loose CSV StringTable assets using the reviewed bounded parser (8 MiB input, row/column limits, padded-cell budget, quoting checks, engine-compatible cell hashes, safe asset paths and stable published storage). Keep upstream's existing dump command. Cache by asset plus actual resolved loose path, so frontend mod-manager mount changes do not keep a different mod's table under the old asset-only key; key published entries by the path actually loaded. Replaced published tables stay alive for engine pointer lifetime. Native mod-switch/runtime validation is still required before submission.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.

## Upstream mod manager integration

The loader selects/mounts a mod root; it does not construct StringTable assets from CSV. Current upstream only recognises mod roots containing scripts or ui_scripts. A folder containing only CSV assets is therefore not a selectable mod under the current validator. Use normal loose asset paths or include overrides in an otherwise valid mod; asset-only mod recognition would be a separate proposal, not a dummy script workaround.

The v2 cache distinguishes the resolved winning path and uses the path actually loaded when publishing an entry. This prevents one selected mod's table from being returned under another path's cache identity. It does not mutate engine pointers already handed out or guarantee instant hot reload of every caller-held table reference. Published storage stays alive intentionally.

Acceptance before submission: select mod A, unload it, select mod B with the same CSV asset name, test a previously missing asset becoming available, and check frontend reload plus a subsequent match. A selected mod and global loose overrides can still collide on the same asset path. Combined builds and cache-key/helper tests pass; those native mod-switch scenarios remain untested.
