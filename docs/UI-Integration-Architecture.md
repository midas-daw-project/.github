# UI Integration Architecture

## Purpose

Define the stable boundary between UI clients and backend services.

## Boundary

```text
UI Client (Qt / Python / future web)
  -> Facade API (midas-core)
    -> subsystem commands/queries/events
```

## Client Rules

- UI sends typed commands and queries through `Facade`.
- UI subscribes to typed events for state updates.
- UI never mutates subsystem internals directly.

## Initial Facade Operations

- `registerSubsystem(...)`
- `submitCommand(...)`
- `subscribe(...)`
- `queryState(...)`

## Evolution

- Add explicit UI-facing service wrappers as needed.
- Keep compatibility by extending contracts, not replacing existing fields abruptly.

## State binding
- UI views bind to queryable state (queries) and subscribe to event categories relevant to their view (e.g., mixer events for mixer UI).
- UI maintains local view state (selection, focus) separately from engine state; only persisted state goes through session/persistence flows.

## Command patterns
- UI should issue minimal, idempotent commands (e.g., `SetGain`, `ToggleMute`, `StartTransport`).
- Batch operations use orchestration commands/services in `midas-core` rather than issuing many subsystem-specific commands ad hoc.

## Error handling
- UI must handle `ResultCode`/`QueryResult` failures gracefully (show non-blocking errors, avoid retry loops on realtime threads).

## Testing stance
- UI integration tests should treat the facade as the only backend boundary (no private subsystem mocks); use contract DTOs.
