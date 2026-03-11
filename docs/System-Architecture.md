# System Architecture

## Purpose

Define the stable backend architecture and module boundaries for MIDAS.

## Layered Model

```text
UI Layer (Qt/Python/Web)
  -> midas-core (Facade, orchestration, command routing)
    -> session-system (snapshot, persistence, reconstruction, apply)
    -> mixer-engine (channel/bus state and signal policy)
    -> audio-engine (device lifecycle and runtime execution)
    -> dsp-engine (processing graph and plugin execution)
    -> shared-contracts (DTOs, commands, queries, events, result codes)
```

## Rules

- UI code does not directly depend on engine internals.
- `midas-core` is the primary integration boundary for UI clients.
- Realtime processing behavior must remain separated from persistence and UI concerns.
- Shared contracts define cross-repo language and must remain backward-compatible where possible.

## Scope vs future
- Current scope: orchestration, session lifecycle, minimal mixer/audio runtime, file persistence.
- Planned: fuller mixer topology, DSP graph execution, richer timeline state, platform audio backends.

## Ownership
- `shared-contracts`: data language only.
- `midas-core`: routing, coordination, provider registries, persistence/reconstruction/apply services.
- `session-system`: session schema, migration, persistence mapping.
- `mixer-engine`: mixer domain state and policy.
- `audio-engine`: device lifecycle + render scheduling.
- `dsp-engine`: processing graph and plugin execution (planned).
- `workspace-modules`: UI/workspace composition (frontend-side).
