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
