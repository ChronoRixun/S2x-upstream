# gun game bot costumes

Base: `26358ffa5091427705a416ef62472ad793bdaf68`. Source extracted from the reviewed CR upstream rebuild; no CR economy, branding, custom names or companion-bot component is included.

Restore a bot's division costume after Gun Game applies a profile-based loadout. Guard to Gun Game only, retain Sandbox special handling, ignore unsupported/empty costume results and keep cached division outfits. The script must be installed through an upstream mod/loose-script package; adding its source alone does not automatically change the publisher's payload manifest.

Validation: this refreshed branch is a proposal, not an upstream-submitted PR. Original CR evidence applies to its prior base; current-upstream Debug/Release and runtime validation are recorded separately. Do not treat a successful compile as engine/runtime certification.

## Upstream mod manager integration

This is a gameplay repair script, not another mod loader. Prefer an explicitly selected MP mod package instead of an unconditional global installation when distributing the fix. Current upstream accepts a mod root with a scripts directory, so the repair can use that existing mechanism without adding a loader.

Gun Game and Sandbox guards limit where the repair runs. They do not resolve conflicts with another script that also changes bot costumes/loadouts. Avoid differently named copies of the same repair and test with any other costume customisation in the selected mod/global loose files.

Acceptance before submission: enable/disable the mod in the frontend, play Gun Game through weapon changes, check unaffected stock MP modes and Sandbox, and test any combined loadout/costume modifications. Source inspection and combined native compilation do not certify those gameplay scenarios.
