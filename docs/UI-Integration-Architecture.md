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
