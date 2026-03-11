# Snapshot Manifest

## Export Metadata
- Export date: 2026-03-11 (America/Phoenix)
- Export script: `download-git-zips.ps1`
- Snapshot directory: `zip-snapshots/`

## Source of Truth SHAs
- root docs repo (`midas-daw-project/.github`): `26e071800d90cbedf1fb8aa4b880800d6e2c7ae7`
- shared-contracts: `fd56d90f245006e78a0458094d294b9ad23e8700`
- session-system: `e80164e34afc6f0dc1f7b047f523e1dde41b2947`
- workspace-modules: `53e0468d935bf8644e87450e93c679d0c856535f`
- dsp-engine: `2ea72d5656071e54e7def72bfd14af33d2966e8a`
- mixer-engine: `950430d4c3d5aab66f3f5ac3c2bb068274a8c592`
- audio-engine: `597934e11cbc8d14cd0cba6a6c3f0da2d2424eb3`
- midas-core: `ebc44b5ee9c3bfbaf016b4a853cd310173d6bfc0`

## Snapshot Files
- `audio-engine-main.zip` (11:21:40 AM, 13,638 bytes)
- `dsp-engine-main.zip` (11:21:38 AM, 5,247 bytes)
- `midas-core-main.zip` (11:21:41 AM, 56,088 bytes)
- `mixer-engine-main.zip` (11:21:39 AM, 9,705 bytes)
- `session-system-main.zip` (11:21:36 AM, 6,418 bytes)
- `shared-contracts-main.zip` (11:21:36 AM, 29,960 bytes)
- `workspace-modules-main.zip` (11:21:37 AM, 5,678 bytes)

## Key File Checks
### shared-contracts (`shared-contracts-main.zip`)
- `include/shared-contracts/TransportHelpers.h` present
- `include/shared-contracts/TrackHelpers.h` present
- `include/shared-contracts/ClipHelpers.h` present
- `include/shared-contracts/NoteHelpers.h` present
- `include/shared-contracts/AutomationHelpers.h` present
- `include/shared-contracts/PluginHelpers.h` present
- `include/shared-contracts/RoutingHelpers.h` present
- `tests/compile_check.cpp` present

### midas-core (`midas-core-main.zip`)
- `docs/Frontend-Engine-Entry-Points.md` present
- `tests/FacadeTests.cpp` present

## Verification
- `shared-contracts-compile-check`: pass
- `midas-core-facade-tests`: pass (19/19)
