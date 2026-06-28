# feat: multi-detector support (one backend per player)

> Stacked on #27 (subprocess backend) — which is stacked on #26. Review/merge in order.

## Summary

Run a **detector per player** so two players can be processed at the same time.
The dock launches one backend for **Player 1** and one for **Player 2**, each
with its own deck lists, and each `Draw Display` source picks which detector it
reads from.

## Changes

- **`src/DrawDock.{cpp,hpp}`** — launch a backend per channel (player 1 and
  player 2); each reads its own deck lists; log lines are tagged `[P1]` / `[P2]`.
- **`src/SettingsDialog.{cpp,hpp}`** — per-player deck-list pickers (3 lists for
  player 1, 3 for player 2).
- **`src/draw.c`** — a **`Detector / Player`** property on the `Draw Display`
  source selects which detector (shared-memory channel) the source reads from;
  changing it re-creates the shared memory under the new channel.
- **`data/locale/en-US.ini`** + README and all translations (`es`/`fr`/`jp`/
  `pt-br`) — strings and usage docs for the two-player workflow.

## Opt-in by configuration

A source defaults to **Player 1**, so existing single-player setups behave
exactly as before — fill in Player 1 and leave Player 2 empty.

## How it was tested

- **Build** — `cmake --preset macos` + `cmake --build build_macos` → universal
  build succeeds.
- This PR is a thin wiring layer on top of the already-validated subprocess
  backend (#27): it launches a second instance of the same backend and adds a
  per-source channel selector. The shared-memory channel addressing already
  exists in #27 (used with channel 1); this PR exposes channel 2.

> A full two-player OBS run (two `Draw Display` sources detecting at once) is a
> manual check best done with a live 2-player capture setup; it does not change
> the single-player behaviour validated in #27.
