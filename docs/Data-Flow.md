# Data Flow

## Control Path

```text
UI Action
  -> Facade Command
    -> Target Subsystem
      -> Result + Event
        -> UI update / session state update
```

Examples:
- Play: UI -> Transport command -> audio-engine (state), events -> UI.
- Add track: UI -> mixer command -> mixer state update -> event -> UI.
- Save session: UI -> snapshot -> persist -> event/log (success/fail).

## Runtime Audio Path

```text
Audio callback context
  -> audio-engine runtime coordination
    -> dsp-engine processing graph
      -> mixer-engine summing/gain/bus policy
        -> device output buffer
```

Notes:
- Audio path is realtime; no blocking calls permitted.
- dsp-engine is planned; current path may be stubbed until graph exists.

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

Rules:
- Snapshot must be additive/non-destructive to live state.
- Migration runs before reconstruction/apply when loading older schema versions.
