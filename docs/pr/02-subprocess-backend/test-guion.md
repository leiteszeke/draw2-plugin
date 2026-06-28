# Guión de prueba — PR2: backend como subprocess (sin libpython embebido)

**Qué valida este PR:** que el backend Python ya **no va embebido** sino como **proceso aparte** comunicado por shared memory, que el **panel de logs** del dock muestra su salida, y que la **detección end-to-end** sigue funcionando. Es el cambio de arquitectura grande.

**Rama:** `up/02-subprocess` (local) — es PR1 (build-fix) + este cambio. **No toca READMEs** (las docs van en PR3).

---

## Precondiciones

- Tener un **prefix de Python con el backend `draw`** instalado (rama `obs-plugin`), igual que en tu setup actual. Si ya venís usando el plugin para streamear, ya lo tenés.
- Modelo/pesos descargados como siempre.

## Paso 1 — Build + instalar (universal, ya sin libpython)

```bash
git -C /private/var/www/discover/forks/draw2-plugin switch up/02-subprocess
cd /private/var/www/discover/forks/draw2-plugin
rm -rf build_macos
cmake --preset macos          # universal: ahora linkea sin libpython
cmake --build build_macos
cp -R build_macos/*/draw2-plugin.plugin \
  "$HOME/Library/Application Support/obs-studio/plugins/"
```

Reiniciá OBS.

📸 **Captura 1** (`01-build-ok`): la terminal con `Build Succeeded` (te la puedo regenerar como imagen, igual que en PR1).

## Paso 2 — Configurar (o confirmar) el backend

En **Draw 2 → settings** (engranaje del dock):
- **Select Python installation** → el prefix con `bin/` y `lib/.../site-packages/draw`.
- Deck lists por jugador, modelo, etc. — como los usás normalmente.

## Paso 3 — Start DRAW: verificar el subprocess + panel de logs

Apretá **Start DRAW** y mirá el **panel de logs** del dock.

**Esperado:**
- Aparecen líneas del backend (carga de modelo, etc.) **en el panel de logs** del dock — eso prueba que corre como proceso aparte y que su stdout llega por el pipe.
- Eventualmente aparece algo tipo *"Waiting for OBS to start"* y el botón pasa a **Stop DRAW**.
- OBS **no crashea** (con libpython embebido + obs-scripting esto chocaba en macOS; ahora no).

📸 **Captura 2** (`02-backend-log`): el dock con el panel de logs mostrando el backend corriendo (idealmente hasta el "Waiting for OBS" / botón en *Stop DRAW*).

## Paso 4 — Detección end-to-end

Mostrá una carta en la entrada capturada (como en un match real).

**Esperado:** la carta se **detecta** y se muestra en la fuente **`DRAW Display`**, igual que siempre.

📸 **Captura 3** (`03-detection`): una carta detectada en pantalla (DRAW Display con el resultado).

## Paso 5 — Stop

Apretá **Stop DRAW**.

**Esperado:** el proceso del backend termina, el panel lo registra (salida/exit), el botón vuelve a **Start DRAW**, sin procesos colgados.

## Reporte

Por cada paso: ✅/❌ + las 3 capturas (o rutas). Si algo falla, copiame las líneas del panel de logs / el error. Con eso cierro la doc de PR2.

> Nota cross-platform: este PR cambia la arquitectura en **todas** las plataformas (Windows/Linux también pasan a subprocess; el shm tiene rama Windows con boost). Eso lo valida la CI de las 3 plataformas cuando se abra el PR upstream — no lo podés probar vos en Windows/Linux desde la Mac.
