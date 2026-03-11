# Development Philosophy

Last verified: 2026-03-11

This captures the build order and quality bar for MIDAS so the team stays aligned.

This is the same discipline used in NestedTech projects (example: Neural Crypto Analysis):
- make the structure correct early
- keep artifacts discoverable and verifiable
- iterate details after the architecture is proven

## Build Order

First (functional, structured, future-real):
- real `QMainWindow`
- real docking
- real backend bridge
- real panels
- real commands/queries/events

Later (refinement and sophistication):
- theming and styling
- panel polish and layout refinement
- animations and onboarding
- store/community surfaces

## Core Question

Do not ask:
- "dev app or complete app?"

Ask:
- "what is the smallest slice of the real app that proves the architecture?"

## Real-but-Plain Rule

The first UI should be:
- architecturally real
- visually modest

The goal is to avoid rebuilding the shell later.

## Keep-or-Throw Test

Everything built now should pass:
- "Would I keep this file/class/module and improve it later, or throw it away?"

If the answer is "throw it away", stop and redesign the slice.

## First MIDAS App Milestone

A user can launch MIDAS and:
- see the real app shell (main window + docks)
- initialize/open/start/stop/close audio
- interact with mixer controls (mute/solo/gain/pan)
- save/load a session
- see backend state and events (status/debug panel)
- rearrange some docks

This is not a toy. It is the beginning of the real product.

## Implementation Shape (UI)

Keep the UI layered:
`Qt Widgets -> Controllers -> typed helper builders -> DefaultFacade`

Widgets remain dumb; controllers own the action map.
