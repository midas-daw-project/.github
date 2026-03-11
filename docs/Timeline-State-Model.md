# Timeline State Model

## Purpose

Define the canonical arrangement model used by UI and session persistence.

## Model

```text
Project
  -> Transport
  -> Tracks[]
    -> Clips[]
      -> Notes[]
    -> PluginChain[]
    -> AutomationLanes[]
  -> MixerState
```

## Required IDs

- `project_id`
- `track_id`
- `clip_id`
- `note_id`
- `plugin_instance_id`
- `automation_lane_id`

## Rules

- Timeline model is UI-agnostic and persistence-safe.
- Clip and note timing are defined in project timeline units.
- Automation and plugin chain references use stable IDs, not index-only addressing.
