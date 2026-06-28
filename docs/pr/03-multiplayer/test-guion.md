# Guión de prueba — PR3: two-player OPT-IN (un backend por jugador)

**Qué valida:** la feature de **dos jugadores es opt-in** (OFF por defecto) y, al activarla, aparecen deck lists de Player 2, el selector "Detector / Player" en la fuente, y se lanzan **dos** detectores. No depende de la detección real.

**Rama:** `up/03-multiplayer`.

## Instalar
```bash
git -C /private/var/www/discover/forks/draw2-plugin switch up/03-multiplayer
cmake --build build_macos
cp -R build_macos/*/draw2-plugin.plugin "$HOME/Library/Application Support/obs-studio/plugins/"
```
Reiniciar OBS.

## Capturas
1. 📸 `01-default-off` — Settings del dock TAL CUAL se abre: en **Advanced features** el toggle **"Enable two players"** está **desmarcado**, y NO hay fila de Player 2 (solo Player 1). (Esto prueba el opt-in / default single-player.)
2. 📸 `02-toggle-on` — Marcá **"Enable two players"**: ahora aparece la fila de deck lists de **Player 2**. Captura con el toggle ON + la fila P2 visible. Dale OK.
3. 📸 `03-channel-selector` — Fuente `DRAW Display` → Propiedades → ahora aparece el dropdown **`Detector / Player`** (Player 1 / Player 2). (Con el toggle OFF NO aparece.)
4. 📸 `04-two-detectors` — Start DRAW → panel de logs con `[P1]` **y** `[P2]` (dos detectores).

## Reporte
✅/❌ por paso + capturas. (Detección de cartas no es necesaria.)
