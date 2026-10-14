# console log path

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Honor an immutable `+set g_consoleLog` launch override while keeping upstream's atomic log-path ownership for worker-thread output. This supersedes the old borrowed-Dvar-string proposal. A host can assign each dedicated process a different log file.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.
