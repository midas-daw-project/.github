# Module Dependency Graph

## Allowed Dependencies

```text
shared-contracts
  ^
  |  | 
  |  +-- mixer-engine
  |  +-- audio-engine
  |  +-- dsp-engine
  |  +-- session-system
  |
  +-- midas-core (orchestration + integration)

workspace-modules -> midas-core + shared-contracts (UI/workspace integration only)
```

## Rules

- No engine module may depend on UI runtime code.
- `shared-contracts` must not depend on engine implementations.
- `midas-core` can depend on subsystem public interfaces, not private internals.
- Cross-subsystem behavior should be coordinated in `midas-core` or explicit coordination services.

## Forbidden
- Engine modules depending on each other’s private headers.
- UI calling subsystems directly (must go through `midas-core` facade).
- `shared-contracts` importing engine headers or platform APIs.

## Coordination patterns
- Cross-subsystem flows (e.g., session snapshot, runtime coordination) live in `midas-core` services that call subsystems via public interfaces.
