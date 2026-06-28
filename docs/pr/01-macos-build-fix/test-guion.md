# Guión de prueba — PR1: fix de build macOS 26 / Xcode 16

**Qué valida este PR:** que el plugin **compila** en macOS 26 / Xcode 16+ (que sin el fix fallaba al linkear con `framework 'AGL' not found`) y que el bundle **carga** en OBS (aparece el dock `Draw 2`). No prueba detección — eso necesita el backend Python y es de PRs posteriores.

**Rama a probar:** `up/01-macos-build` (local). Es `master` del owner + solo el fix de build.

---

## Precondiciones

- macOS 26+ (Apple Silicon), Xcode 16+ con command line tools.
- Prerequisitos Homebrew (si no los tenés):
  ```bash
  brew install cmake ccache coreutils jq xcbeautify
  ```
- Las deps de OBS ya están en `.deps/` de este repo (no hay que bajar nada).

## Paso 1 — Build desde cero (esto es el corazón del PR)

```bash
git -C /private/var/www/discover/forks/draw2-plugin switch up/01-macos-build
cd /private/var/www/discover/forks/draw2-plugin
rm -rf build_macos
cmake --preset macos -DCMAKE_OSX_ARCHITECTURES=arm64
cmake --build build_macos
```

**Esperado:** termina con `** BUILD SUCCEEDED **` (o sin errores) y existe el bundle:
```bash
ls -d build_macos/*/draw2-plugin.plugin
```

📸 **Captura 1:** la terminal mostrando el build exitoso (las últimas líneas con `BUILD SUCCEEDED` + el `ls` del `.plugin`). Guardar como `screenshots/01-build-ok.png`.

> Para confirmar que el fix es lo que arregla esto: en `master` pelado el mismo build falla con `ld: framework 'AGL' not found`. No hace falta que lo reproduzcas, pero si querés: `git stash`-eás nada y probás en `upstream/master`.

## Paso 2 — Instalar el plugin en OBS

```bash
mkdir -p "$HOME/Library/Application Support/obs-studio/plugins"
cp -R build_macos/*/draw2-plugin.plugin \
  "$HOME/Library/Application Support/obs-studio/plugins/"
```

Cerrá y volvé a abrir OBS.

## Paso 3 — Verificar que carga en OBS

1. Abrí OBS.
2. Menú **Docks** (o `Docks` en la barra superior).

**Esperado:** aparece la opción **`Draw 2`** en el menú Docks.

📸 **Captura 2:** el menú `Docks` desplegado mostrando `Draw 2`. Guardar como `screenshots/02-docks-menu.png`.

3. Activá el dock `Draw 2`.

**Esperado:** el dock se abre sin errores (vas a ver los controles de Draw 2 / panel de logs).

📸 **Captura 3:** el dock `Draw 2` abierto. Guardar como `screenshots/03-dock-open.png`.

> Nota: en este PR el backend sigue siendo Python embebido del owner; no probamos "Start DRAW" todavía. Si OBS abre y el dock aparece sin crashear, el PR está OK.

## Reporte

Decime por cada paso: ✅/❌ y pegame las 3 capturas (o sus rutas). Si algo falla, copiame el error textual. Con eso cierro la documentación del PR1 y paso al PR2.
