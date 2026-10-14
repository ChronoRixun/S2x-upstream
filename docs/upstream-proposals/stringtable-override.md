# stringtable override

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Build loose CSV StringTable assets using the reviewed bounded parser (8 MiB input, row/column limits, padded-cell budget, quoting checks, engine-compatible cell hashes, safe asset paths and stable published storage). Keep upstream's existing dump command. Cache by asset plus actual resolved loose path, so frontend mod-manager mount changes do not keep a different mod's table under the old asset-only key; key published entries by the path actually loaded. Replaced published tables stay alive for engine pointer lifetime. Native mod-switch/runtime validation is still required before submission.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.
