# Documentation Depth Standard

Last verified: 2026-03-11

This file defines the required depth level for canonical docs in this repository.
It exists so standards remain stable even if chat context compacts.

This is patterned after the NestedTech Neural Crypto Analysis documentation discipline:
- a small set of canonical root docs
- explicit depth requirements
- navigation via `docs/README.md` and `docs/index.md`

## Purpose

Use this standard to decide whether a doc is complete or still a placeholder.

## Canonical Layers

1. Root docs (`docs/*.md`) are authoritative for architecture boundaries and global rules.
2. Module docs (`<repo>/docs/*.md`) are authoritative for repo-local responsibilities and interfaces.
3. Shared contracts docs (`shared-contracts/docs/*.md`) are authoritative for cross-repo DTO semantics.

## Required Depth: Root Architecture Docs

A root architecture doc is complete only if it includes all of the following:
1. Scope and non-goals (what it covers, what it does not).
2. Clear rules (allowed/forbidden behavior).
3. One concrete example flow or scenario.
4. Links to the module docs it depends on.

## Required Depth: Module Docs

A module doc set is complete only if it includes:
1. `overview.md`: one-page description of the module.
2. `responsibilities.md`: what it owns and does not own.
3. `interfaces.md`: public contract surface and key types.
4. `non-goals.md`: explicit exclusions to prevent creep.
5. `architecture.md`: key internal structure and execution model.
6. `future-work.md`: planned evolution without committing to implementation details too early.

## Required Depth: Contract / Helper Docs

Contract docs are complete only if they include:
1. Required vs optional fields.
2. ID ownership and lifecycle rules.
3. Units and encoding rules where relevant (time units, gain units, etc).
4. One example payload (JSON or equivalent), even if the on-wire format differs.
5. Compatibility guidance (additive changes preferred; avoid breaking changes).

## Maintenance Rule

When materially editing a covered doc:
1. update its "Last verified" date;
2. keep this standard unchanged unless intentionally revising policy;
3. update relevant indexes/links so docs remain discoverable.
