# chat notify

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Expose only stock-handled `say`/`say_team` as a bounded script event after the native handler. Copy text before callbacks retokenize arguments; strip the normal chat marker; limit to 256 bytes; do not emit for consumed commands, invalid players or virtual lobbies. No additional CR script APIs or moderation policy is added.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.
