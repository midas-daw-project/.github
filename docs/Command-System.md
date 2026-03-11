# Command System

## Purpose

Define command execution semantics and undo/redo direction.

## Command Pattern

```text
Command
  -> execute()
  -> undo() (when reversible)
```

## Initial Command Domains

- Transport (play/stop/seek)
- Mixer (mute/gain)
- Device/Audio lifecycle (init/open/start/stop/close)
- Session operations (snapshot/save/load/apply)

## Requirements

- Commands carry stable IDs and target subsystem IDs.
- Results use typed `ResultCode` values.
- Event emission after command execution must be deterministic.
- Undo/redo support should be explicit per command type.
