# feat: opt-in detector input crop and 180° rotation

> Stacked on #27 (subprocess backend). Review/merge in order.

## Summary

Two **opt-in** per-source tweaks to what the detector sees (not your live
output), both **off by default**:

- **Crop** — remove pixels from each edge of the captured input, to focus
  detection on the region where cards are placed.
- **180° rotation** — for a camera mounted upside down.

## Changes

- **`src/feature_flags.{h,cpp}`** — opt-in toggle infrastructure
  (`draw_feature_enabled`, backed by QSettings) with `FEATURE_CROP` /
  `FEATURE_ROTATE`.
- **`src/draw.c`** — when enabled, the `Draw Display` source gains Crop
  (L/T/R/B px) and a Rotate-180° toggle, applied to the captured frame before
  it reaches the detector. Disabled features force neutral values.
- **`src/SettingsDialog.{cpp,hpp}`** — "Enable detector input crop" /
  "Enable 180° input rotation" toggles under "Advanced features".
- **README + all translations** (`es`/`fr`/`jp`/`pt-br`) and `fr`/`ja` locale
  strings.

## Opt-in / default behaviour

Both features are off by default; with them off the source has no crop/rotate
fields and the plugin behaves exactly like upstream.

![Advanced features — both off by default](https://raw.githubusercontent.com/leiteszeke/draw2-plugin/pr-docs/docs/pr/03-crop-rotation/screenshots/01-toggles-off.png)

## How it was tested

Environment: macOS 26, OBS Studio 32.1.1, a real capture (phone camera mounted
upside down, framing a play mat).

**Crop fields on the source** — with the crop feature enabled, the `Draw Display`
source exposes the Crop (Left/Top/Right/Bottom) fields:

![Crop fields on the source](https://raw.githubusercontent.com/leiteszeke/draw2-plugin/pr-docs/docs/pr/03-crop-rotation/screenshots/02-source-crop.png)

**End-to-end detection** — with crop + 180° rotation enabled, the cropped,
upright frame is fed to the detector, which recognises the card on the mat
(*Satellarknight Deneb*) and renders it on the `Draw Display` overlay (the dock
log shows `Sent image 813x1185 to OBS`):

![Detected card displayed](https://raw.githubusercontent.com/leiteszeke/draw2-plugin/pr-docs/docs/pr/03-crop-rotation/screenshots/03-detection.png)

The universal plugin build also succeeds (`cmake --preset macos`).
