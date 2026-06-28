# feat(backend): run the Python backend as a subprocess (drop embedded libpython)

> Stacked on #26 (macOS build fix). Review/merge that first.

## Summary

Stop embedding libpython in the plugin. Instead, launch the user's Python as a
**separate process** and communicate with it over **shared memory**. This is a
cross-platform change motivated by macOS, where embedding the interpreter is
not viable.

## Motivation

Linking libpython into the plugin and running the backend in-process has two
problems:

- **On macOS it clashes with OBS' own `obs-scripting` Python symbols**, and
  importing `numpy`/`torch` in-process crashes.
- It forces the plugin to be built against — and ship with — one specific
  Python ABI, and pins the user to that exact interpreter version.

Running the backend as a subprocess removes the symbol clash entirely and lets
the user point the plugin at any compatible Python that has the `draw` package
installed.

## Changes

- **`CMakeLists.txt`** — drop `find_package(Python3)` and the include/link
  step. The plugin no longer embeds an interpreter.
- **`src/DrawDock.{cpp,hpp}`** — launch the backend with `QProcess`; stream its
  stdout into a **log panel** in the dock; manage **per-player deck lists** from
  a `decklists` folder in the OBS plugin config dir; start/stop lifecycle.
- **`src/shared_memory_wrapper.cpp`** — shared-memory transport between the
  plugin and the backend. Cross-platform: `shm_open`/`mmap` on Unix/macOS,
  `boost::interprocess::windows_shared_memory` on Windows (matching Python's
  `multiprocessing.shared_memory`).
- **`src/SettingsDialog.{cpp,hpp}`** — select the Python prefix and the
  per-player deck-list files used at launch.
- **`data/locale/en-US.ini`** — strings for the new dock controls.

## Cross-platform

- The shared-memory layer has a Windows path (`windows_shared_memory`) and a
  Unix path (`shm_open`/`mmap`); `QProcess` is cross-platform.
- The 3-platform CI on this PR (macOS / Ubuntu / Windows) is the build check.

## Behaviour change (worth a maintainer's attention)

The plugin no longer bundles a Python interpreter on any platform. Users now
select a Python install that has the `draw` backend package. The user-facing
setup documentation is added in a **follow-up docs PR** (kept separate so the
docs describe this final subprocess model rather than the old embedded one).

## How it was tested

Environment: macOS 26 (Apple Silicon), OBS Studio 32.1.1, a Python prefix with
the `draw` backend (`obs-plugin` branch) installed.

- **Build** — `cmake --preset macos` + `cmake --build build_macos` →
  **universal build succeeds** (no libpython link; the previous arm64-only
  constraint from embedding Homebrew's Python is gone). <!-- screenshot 01 -->
- **Backend launches as a subprocess** — Start DRAW spawns the Python process;
  its output streams into the dock log panel; the dock reports readiness and the
  button switches to Stop DRAW. <!-- screenshot 02 -->
- **End-to-end detection** — a card shown on the captured input is detected and
  rendered on the `DRAW Display` source. <!-- screenshot 03 -->

<!-- screenshots embedded after manual OBS test -->
