# Data Flow

## Control Path

```text
UI Action
  -> Facade Command
    -> Target Subsystem
      -> Result + Event
        -> UI update / session state update
```

## Runtime Audio Path

```text
Audio callback context
  -> audio-engine runtime coordination
    -> dsp-engine processing graph
      -> mixer-engine summing/gain/bus policy
        -> device output buffer
```

## Session Lifecycle Path

```text
Live subsystem state
  -> SessionSnapshotService
    -> PersistedSession mapping
      -> Persistence backend (memory/file)
        -> Load + migration
          -> Reconstruction
            -> Apply to live subsystems
```
