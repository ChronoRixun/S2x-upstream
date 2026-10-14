# dedicated bot fill

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Opt-in `bot_fill` at map startup, bounded by owned match slots. Recount transient native refusals a limited number of times on the server pipeline and cancel work when the level generation changes. Preserve listen-server stock spawn-thread setup and clean up its reference on shutdown. This is not continuous auto-balance, human-slot reservation, a custom-name pool, or a Zombies companion feature; automatic fill is MP-only. This supersedes the old playlist-number bypass.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.
