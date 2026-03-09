# Engineering-Baseline

## Purpose

This document defines the default development contract for the MIDAS backend repositories and lives at the root of the top-level coordination/meta repo (`midas-daw-project`). It describes how backend code is built, formatted, linted, tested, named, and reviewed before we branch into feature work. Frontend/UI repositories may adopt different standards in the future, but they should be explicitly documented elsewhere when that happens.

## Language and toolchain baseline

* **C++20** is our baseline language standard. It is modern enough for cleaner abstractions, broadly supported, and lower risk than moving to C++23 right now. All backend repos should target C++20 as the default compile level.
* **Compiler support**: Primary early target is Linux with Clang or GCC, with Windows/MSVC support as a required near-term goal and macOS kept on the roadmap if the project expands there.

## Build system

* **CMake** is the shared build system across backend repos. It remains the most flexible option for multi-repo C++ work and lets us describe libraries, executables, tests, and tooling from a common set of scripts.

## Repository layout conventions

Each backend repo should eventually follow this predictable structure:

* `include/` for public headers
* `src/` for implementation
* `tests/` for unit and integration tests
* `docs/` for architecture/interface/non-goal documentation
* `CMakeLists.txt` at the repo root describing the targets

## Formatting and linting

* **clang-format** with a shared configuration enforces consistent formatting across repos. Developers should run it before commits and integrate it into CI over time.
* **clang-tidy** is the baseline static analysis tool for detecting common issues early. Each repo should configure a sensible set of checks that focus on safety, style, and realtime correctness.

## Testing expectations

* Unit tests are required for core logic, especially in engine and coordination layers.
* We recommend **GoogleTest** as the shared framework because it is well known and fits our enterprise-style baseline. Frontends or special domains may choose Catch2 later with clear justification.

## Dependency policy

* Minimize third-party dependencies. Every dependency must be documented, justified, and versioned explicitly.
* Avoid hidden runtime dependencies. Prefer portable, actively maintained libraries that work across GCC, Clang, and MSVC.

## Branching and pull request standards

* Use feature branches for work targeting `main`.
* Pull requests are required to merge into `main` across all backend repos.
* Non-trivial changes need at least one review. Architecture-affecting changes must include documentation updates in the relevant repo.

## Documentation requirements

* Architecture-impacting or public-interface changes must update the appropriate `docs/` files in each repo.
* Every backend README should stay current with scope, responsibilities, and status.

## Realtime safety rules

* No blocking operations in the realtime/audio callback path.
* Avoid dynamic allocations in realtime code unless unavoidable (and document it).
* No locks in the realtime path unless explicitly justified, documented, and audited.
* Use explicit cross-thread messaging patterns to keep realtime/non-realtime boundaries clean.

## Future expansion notes

This baseline does not yet define packaging/distribution, advanced CI/CD matrices, sandboxing policy, or custom compiler tricks. Those topics belong in follow-up docs once the basic toolchain and contracts are stable.
