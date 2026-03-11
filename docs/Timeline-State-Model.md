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

## Field expectations (high level)
- Track: `track_id`, `name`, `type` (audio/midi/aux), `order_index`, `mute`, `solo`, `armed`.
- Clip: `clip_id`, `track_id`, `start`, `duration`, `kind` (audio/midi), `source_ref`.
- Note: `note_id`, `clip_id`, `pitch`, `velocity`, `start`, `duration`.
- Automation lane: `automation_lane_id`, `target_id`, `param_id`, `curve` points.
- Plugin chain: ordered plugin instances per track/bus.

## Transient vs persisted
- Persisted: arrangement content (tracks, clips, notes, automation), plugin chain ordering, transport state.
- Transient/UI-only: selection, viewport, in-progress edits; not persisted.
