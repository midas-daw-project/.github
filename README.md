# MIDAS DAW Project

MIDAS stands for **Modular Interactive Digital Audio Suite**.

This organization is building a **modular DAW backend platform** with a backend-first, contract-first architecture that can support multiple frontend experiences over time.

## Vision

MIDAS is not intended to be a single fixed-workflow DAW. The long-term direction is:

* modular workflow surfaces (mixer, arranger, piano roll, recording, browser, utility panels)
* stable backend contracts and orchestration
* frontend flexibility through a single backend-facing interface
* future platform potential (plugin ecosystem, marketplace, community features)

## Repository Map

* `shared-contracts`: shared DTOs, commands/events/queries, categories, helper builders, subsystem interfaces, runtime/session contracts
* `midas-core`: orchestration façade and coordination services (routing, snapshot, persistence, reconstruction, apply/restore)
* `mixer-engine`: mixer subsystem foundation (channel state, mute/gain, mixer command/query flow)
* `audio-engine`: audio runtime lifecycle subsystem foundation (init/open/start/stop/close and runtime state exposure)
* `session-system`: session domain repo reserved for broader session ownership as the project evolves
* `workspace-modules`: future modular workspace runtime/contracts
* `dsp-engine`: future DSP processing subsystem/contracts

## Current Backend Status

Implemented and validated:

* shared contract system with typed domain helpers
* working `DefaultFacade` orchestration path
* real mixer subsystem path in `mixer-engine`
* real audio subsystem lifecycle path in `audio-engine`
* typed runtime coordination seam between mixer and audio
* session snapshot provider model and registry
* persistence lifecycle: snapshot -> persist -> load -> reconstruct -> apply
* file-backed persistence with schema version and migration seam
* compile-check and test coverage across façade and session lifecycle flows

## Engineering Baseline

* C++20
* CMake
* `clang-format`
* `clang-tidy`
* GoogleTest
* feature branches + PR review for non-trivial changes
* docs updates required when architecture/interfaces change

See [Engineering-Baseline.md](Engineering-Baseline.md) for the project-wide baseline.

## Key Docs

* [Backend Architecture](midas-core/docs/Architecture.md)
* [Future Platform Concepts](midas-core/docs/Future-Platform-Concepts.md)
* [Persistence Policy](midas-core/docs/Persistence-Policy.md)
* [Runtime State Contract](shared-contracts/docs/Runtime-State-Contract.md)
* [Current Status Handoff](docs/handoffs/midas-current-status-handoff.md)

## Immediate Priorities

* deepen runtime coordination behavior between mixer and audio
* evolve mixer and audio subsystems from minimal state/lifecycle into richer runtime behavior
* continue hardening persistence/migration and cross-subsystem contracts
* begin structured frontend integration planning against existing backend contracts

## Notes

This repository acts as the top-level coordination/meta repository for MIDAS backend planning, standards, and cross-repo documentation.
