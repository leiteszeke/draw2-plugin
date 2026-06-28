# Guión de prueba — PR3: multi-detector (un backend por jugador)

**Qué valida:** que el plugin maneja **dos jugadores** — deck lists per-player, un selector "Detector / Player" por fuente, y **dos backends** corriendo a la vez. No depende de la detección real (se ve aunque no haya deck/cartas).

**Rama:** `up/03-multiplayer` (= #27 subprocess + multiplayer).

## Instalar
```bash
git -C /private/var/www/discover/forks/draw2-plugin switch up/03-multiplayer
cmake --build build_macos
cp -R build_macos/*/draw2-plugin.plugin "$HOME/Library/Application Support/obs-studio/plugins/"
```
Reiniciar OBS.

## Capturas
1. 📸 `01-settings-2players` — Settings del dock: dos filas de deck lists (Player 1 y Player 2, 6 combos).
2. 📸 `02-channel-selector` — Fuente `DRAW Display` → Propiedades → dropdown `Detector / Player` (Player 1 / Player 2).
3. 📸 `03-two-detectors` — Start DRAW → panel de logs con líneas `[P1]` **y** `[P2]` (dos detectores lanzados).

## Reporte
✅/❌ por paso + las 3 capturas. (Detección de cartas no es necesaria para este PR.)
