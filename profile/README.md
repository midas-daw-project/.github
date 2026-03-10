# MIDAS DAW Project

MIDAS stands for **Modular Interactive Digital Audio Suite**.

MIDAS is being built as a **modular DAW backend platform** with a backend-first, contract-first architecture designed to support flexible frontend workflows over time.

## What MIDAS Is Building

* modular DAW workflow foundations
* stable backend orchestration and contracts
* session lifecycle infrastructure (capture, persist, reconstruct, apply)
* subsystem-based runtime architecture

## Repositories

* `shared-contracts`
* `session-system`
* `workspace-modules`
* `dsp-engine`
* `mixer-engine`
* `audio-engine`
* `midas-core`

## Current Focus

* strengthen runtime coordination between mixer and audio
* continue subsystem maturation in `mixer-engine` and `audio-engine`
* harden persistence and migration behavior
* keep backend interfaces stable for future frontend integration

## Current Status

The project already has:

* a real shared contract layer
* a working orchestration façade in `midas-core`
* minimal real subsystem paths in `mixer-engine` and `audio-engine`
* tested session persistence/reconstruction/apply flow

The project is **not** frontend-complete yet and remains backend-first by design.

## Documentation

* backend architecture: `midas-core/docs/Architecture.md`
* future platform concepts: `midas-core/docs/Future-Platform-Concepts.md`
* persistence policy: `midas-core/docs/Persistence-Policy.md`
* runtime state contract: `shared-contracts/docs/Runtime-State-Contract.md`
* current handoff: `docs/handoffs/midas-current-status-handoff.md`
