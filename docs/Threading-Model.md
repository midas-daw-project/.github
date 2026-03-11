# Threading Model

## Purpose

Define realtime-safe thread responsibilities and cross-thread communication rules.

## Threads

- Audio Thread: hard realtime render callback execution; no blocking I/O.
- UI Thread: user interaction, visualization, and command dispatch.
- Worker Threads: non-realtime compute (analysis, preprocessing, non-critical transforms).
- Disk/Persistence Thread: session save/load and migration processing.

## Hard Realtime Constraints

- No locks with unbounded wait on audio thread.
- No filesystem access on audio thread.
- No heap-heavy allocation in steady-state callback path.
- Communication into audio thread uses bounded queues or preallocated state snapshots.

## Messaging Rules

- UI -> core uses command DTOs.
- Core -> subsystems uses typed command/query/event contracts.
- Audio thread publishes minimal telemetry/events for non-realtime consumers.

## Forbidden on audio thread
- Blocking locks, blocking I/O, allocations that can fail, logging that blocks.
- Access to UI state or persistence services.

## State ownership
- Audio thread owns render buffers during callback window only.
- Shared state accessed across threads must be protected via lock-free/bounded mechanisms; no shared mutable UI objects.

## Scheduling assumptions (current)
- Audio callback cadence determined by backend sample rate and buffer size.
- Transport/timebase authority not yet finalized; treat audio clock as primary until transport sync is defined.
