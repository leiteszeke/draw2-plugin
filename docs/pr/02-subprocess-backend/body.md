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
  stdout into a **log panel** in the dock; manage **deck lists** from a
  `decklists` folder in the OBS plugin config dir; start/stop lifecycle.
- **`src/shared_memory_wrapper.cpp`** — shared-memory transport between the
  plugin and the backend. Cross-platform: `shm_open`/`mmap` on Unix/macOS,
  `boost::interprocess::windows_shared_memory` on Windows (matching Python's
  `multiprocessing.shared_memory`).
- **`src/SettingsDialog.{cpp,hpp}`** — select the Python prefix and the
  deck-list files used at launch.

> Single-player. Multi-detector / per-player support (a second detector and
> per-player deck lists) is deferred to its own PR.
- **`data/locale/en-US.ini`** — strings for the new dock controls.

## Cross-platform

- The shared-memory layer has a Windows path (`windows_shared_memory`) and a
  Unix path (`shm_open`/`mmap`); `QProcess` is cross-platform.
- The 3-platform CI on this PR (macOS / Ubuntu / Windows) is the build check.

## Behaviour change (worth a maintainer's attention)

The plugin no longer bundles a Python interpreter on any platform. Users now
select a Python install that has the `draw` backend package. This PR updates the
README (and all translations — `es`/`fr`/`jp`/`pt-br`) accordingly: building from
source is now a universal build, and the macOS Python-backend setup is documented
for this subprocess model.

## How it was tested

Environment: macOS 26 (Apple Silicon), OBS Studio 32.1.1, a Python prefix with
the `draw` backend installed.

This PR's scope is the **process model**, not the detection pipeline (the
capture + model code in `src/draw.c` is untouched here), so the test confirms
the backend now runs out-of-process and the plugin talks to it:

**Build** — `cmake --preset macos` + `cmake --build build_macos` → **universal
build succeeds** (no libpython link; the previous arm64-only constraint from
embedding Homebrew's Python is gone).

![Universal build succeeds](https://raw.githubusercontent.com/leiteszeke/draw2-plugin/pr-docs/docs/pr/02-subprocess-backend/screenshots/01-build-ok.png)

**Backend runs as a separate process** — Start DRAW spawns the Python backend;
its stdout streams into the dock's log panel (impossible with an in-process
interpreter), the plugin and backend connect over shared memory
(`Shared memory found`), and OBS does **not** crash — the libpython/obs-scripting
symbol clash on macOS is gone.

![Backend subprocess running, shared memory connected](https://raw.githubusercontent.com/leiteszeke/draw2-plugin/pr-docs/docs/pr/02-subprocess-backend/screenshots/02-backend-log.png)

> Detection itself is unchanged by this PR (same `draw.c` capture + model as
> before), so it is not re-validated here.
