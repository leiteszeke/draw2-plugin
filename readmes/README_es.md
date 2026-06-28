<div align="center">
  <p>
    <img src="https://raw.githubusercontent.com/HichTala/draw2/refs/heads/main/figures/banner-draw.png" alt="DRAW Banner">
  </p>
<div>

[![DRAW2 Workflow](https://github.com/HichTala/draw2-plugin/actions/workflows/push.yaml/badge.svg)](https://github.com/HichTala/draw2-plugin/actions/workflows/push.yaml)
[![Licence](https://img.shields.io/pypi/l/ultralytics)](../LICENSE)
[![Github](https://img.shields.io/badge/-github-181717?logo=github&labelColor=555)](https://github.com/HichTala/draw2)
[![Twitter](https://img.shields.io/badge/-twitter-000?logo=x&labelColor=555)](https://twitter.com/hichtala)
[![HuggingFace Downloads](https://img.shields.io/badge/dynamic/json?url=https%3A%2F%2Fhuggingface.co%2Fapi%2Fmodels%2FHichTala%2Fdraw2&query=%24.downloads&logo=huggingface&label=downloads&color=%23FFD21E)](https://huggingface.co/HichTala/draw2)
[![Medium](https://img.shields.io/badge/-Medium-12100E?style=flat&logo=medium&labelColor=555)](https://medium.com/@hich.tala.phd/how-i-trained-again-my-model-to-detect-and-recognise-a-wide-range-of-yu-gi-oh-cards-5c567a320b0a)
[![WandB](https://img.shields.io/badge/visualize_in-W%26B-yellow?logo=weightsandbiases&color=%23FFBE00)](https://wandb.ai/hich_/draw)

[🇬🇧 English](../README.md) | [🇫🇷 Français](README_fr.md) | [🇧🇷 Português](README_pt-br.md) | [🇯🇵 日本語](README_jp.md)

</div>

</div>

DRAW 2 (que significa **D**etect and **R**ecognize **A** **W**ide range of cards version 2 — detectar y reconocer una
amplia gama de cartas, versión 2) es un detector de objetos entrenado para detectar cartas de _Yu-Gi-Oh!_ en todo tipo
de imágenes, y en particular en imágenes de duelos.

Este proyecto es la parte de plugin del sistema DRAW 2. Permite a los usuarios integrar el detector directamente en sus
directos o vídeos grabados, y todo ello **sin necesidad de conocimientos técnicos particulares**.
El plugin puede mostrar las cartas detectadas en tiempo real para mejorar la experiencia de quienes lo ven.
El proyecto del backend de Python está disponible [aquí](https://github.com/HichTala/draw2).

Este proyecto está licenciado bajo la [GNU Affero General Public License v3.0](LICENCE); ¡todas las contribuciones son
bienvenidas!

---

## <div align="center">📰 Novedades</div>

> 🃏 **Último pool de cartas:** `BLZD` --- última actualización `18-05-2026`
> 🔧 **Última versión de la app:** `0.2.1-beta` --- última actualización `01-06-2026`

<table>
  <tr>
    <th>Fecha</th>
    <th>Tipo</th>
    <th>Descripción</th>
  </tr>
  <tr>
    <td><b>01-06-2026</b></td>
    <td>🔧 Versión de la app</td>
    <td>Versión 0.2.1-beta publicada --- <a href="https://github.com/HichTala/draw2-plugin/releases/tag/0.2.1">ver notas de la versión</a></td>
  </tr>
  <tr>
    <td><b>18-05-2026</b></td>
    <td>🃏 Pool de cartas</td>
    <td>Pool de cartas actualizado --- ahora admite cartas hasta <i>Blazing Dominion</i></td>
  </tr>
  <tr>
    <td><b>06-04-2026</b></td>
    <td>🃏 Pool de cartas</td>
    <td>Pool de cartas actualizado --- ahora admite cartas hasta <i>Maze of Muertos</i></td>
  </tr>
  <tr>
    <td><b>06-04-2026</b></td>
    <td>🔧 Versión de la app</td>
    <td>Versión 0.2.0-beta publicada --- <a href="https://github.com/HichTala/draw2-plugin/releases/tag/0.2.0">ver notas de la versión</a></td>
  </tr>
  <tr>
    <td><b>09-03-2025</b></td>
    <td>🔧 Versión de la app</td>
    <td>Versión 0.1.5-alpha publicada --- <a href="https://github.com/HichTala/draw2-plugin/releases/tag/0.1.5">ver notas de la versión</a></td>
  </tr>
  <tr>
    <td><b>24-08-2025</b></td>
    <td>🃏 Pool de cartas</td>
    <td>Pool de cartas actualizado --- ahora admite cartas hasta <i>Justic Hunter</i></td>
  </tr>
</table>

---

## <div align="center">📄 Documentación</div>

### 🛠️ Instalación

Sigue las instrucciones de instalación según tu sistema operativo para que todo funcione correctamente:

<details open>
<summary>🪟 Windows</summary>

1. Descarga el instalador del plugin desde este
   enlace: [DRAW2 Plugin Installer](https://github.com/HichTala/draw2-plugin/releases/download/0.2.1/draw2-plugin-installer.exe)
2. Ejecuta el instalador y sigue las instrucciones en pantalla.
3. Una vez completada la instalación, abre OBS Studio. Si todo está configurado correctamente, deberías ver en el
   menú `Docks` una nueva opción llamada `Draw 2`. Puedes activar el dock y colocarlo donde quieras.

   ¡La instalación ha terminado, ya puedes disfrutar detectando!

</details>

<details>
<summary>🐧 Linux</summary>

Próximamente 👀

</details>

<details>
<summary>🍏 MacOS</summary>

No conozco OBS en macOS lo suficiente como para ofrecer una guía de instalación fiable.
El plugin compila correctamente en macOS, pero no lo he probado a fondo.
Si tienes experiencia con plugins de OBS en macOS y quieres contribuir con una guía de instalación,
no dudes en enviar un pull request.

#### Compilar desde el código fuente (Apple Silicon / macOS 26+)

Todavía no hay una versión precompilada para macOS, así que tienes que compilar el plugin tú mismo.

1. Instala los requisitos de compilación con [Homebrew](https://brew.sh):

   ```bash
   brew install cmake ccache coreutils jq xcbeautify
   ```

   También necesitas un **Xcode** reciente (con sus herramientas de línea de comandos) y una instalación de
   **Python 3** (`brew install python`).

2. Configura y compila. En Apple Silicon, compila solo para la arquitectura del host —
   el preset universal también compilaría una porción `x86_64`, que falla al enlazar
   porque el Python de Homebrew es solo `arm64`:

   ```bash
   cmake --preset macos -DCMAKE_OSX_ARCHITECTURES=arm64
   cmake --build build_macos --config RelWithDebInfo
   ```

   En un Mac con Intel, usa `-DCMAKE_OSX_ARCHITECTURES=x86_64` en su lugar.

3. El bundle del plugin compilado se genera en:

   ```
   build_macos/RelWithDebInfo/draw2-plugin.plugin
   ```

4. Instálalo copiando el bundle en tu carpeta de plugins de OBS y luego reinicia OBS:

   ```bash
   mkdir -p "$HOME/Library/Application Support/obs-studio/plugins"
   cp -R build_macos/RelWithDebInfo/draw2-plugin.plugin \
     "$HOME/Library/Application Support/obs-studio/plugins/"
   ```

   Una vez que OBS se reinicie, el plugin aparece como `Draw 2` en el menú `Docks`.

#### Configurar el backend de Python (macOS)

El plugin incorpora un intérprete de Python e importa el backend `draw` desde una
instalación de Python que **tú** proporcionas en los ajustes (`Select Python installation`).
Todavía no hay descarga automática en macOS, así que debes configurarlo manualmente.

> ⚠️ Debe ser un **prefijo de Python completo (con la biblioteca estándar)**, _no_ un
> `venv`/`virtualenv`. El plugin establece `PYTHONHOME` en la carpeta que selecciones; un
> venv no tiene allí la stdlib y la inicialización falla con
> `ModuleNotFoundError: No module named 'encodings'`.
>
> La **versión menor de Python debe coincidir con aquella contra la que se enlazó el plugin**
> (actualmente 3.13). Compruébalo con `otool -L .../draw2-plugin | grep -i python`.

1. Consigue un CPython autocontenido que coincida con esa versión. Una compilación reubicable de
   [python-build-standalone](https://github.com/astral-sh/python-build-standalone)
   funciona bien y no se romperá con `brew upgrade`:

   ```bash
   # pick the install_only build for your arch (aarch64 for Apple Silicon)
   curl -fL -o python.tar.gz \
     https://github.com/astral-sh/python-build-standalone/releases/download/<tag>/cpython-3.13.<x>+<tag>-aarch64-apple-darwin-install_only.tar.gz
   mkdir -p ~/.draw2-runtime && tar -xzf python.tar.gz -C ~/.draw2-runtime
   ```

2. Instala el backend `draw` en ese prefijo. Usa la **rama `obs-plugin`** —
   esa es la que expone el punto de entrada `draw.run(...)` que el plugin llama
   (la rama por defecto `main` es la CLI independiente y no tiene `run`, así que el dock
   registrará `Failed to import draw module` / `Failed to find or call draw run function`):

   ```bash
   ~/.draw2-runtime/python/bin/python -m pip install "git+https://github.com/HichTala/draw2@obs-plugin"
   ```

3. En los ajustes de Draw 2, establece **Select Python installation** en la carpeta del prefijo
   (la que contiene `bin/` y `lib/`), p. ej. `~/.draw2-runtime/python`.
   Verifica la estructura que espera el plugin:

   ```text
   <prefix>/bin/python
   <prefix>/lib/python3.13/site-packages/draw
   ```

   </details>

### 🚀 Uso

Cuando el plugin está instalado y los pesos del modelo están descargados, puedes abrir OBS Studio.

1. Abre el menú `Docks` y selecciona `Draw 2` para activar el dock del plugin. Además del botón `Start DRAW`, el dock
   muestra un panel de logs donde se imprimen el progreso del backend y los posibles errores.
2. En el dock de Draw 2 puedes configurar los ajustes del plugin haciendo clic en el icono de engranaje junto al
   botón `Start DRAW`:
   - **Select Python installation**: ruta al prefijo de Python que tiene instalado el backend `draw` (la carpeta que
     contiene `bin/` y `lib/`). Debe ser una instalación de Python completa, no un virtualenv. Consulta la sección de
     configuración de macOS para más detalles.
   - **Select Deck Lists to use**: elige los archivos de deck list que contienen las cartas que quieres detectar. Se
     pueden gestionar hasta 3 deck lists a la vez, y puedes configurar un conjunto distinto para el **Jugador 1** y el
     **Jugador 2**. Para añadir nuevas deck lists, haz clic en el botón
     `Open Folder` y arrastra y suelta tus archivos de deck list (en formato ydk) en la carpeta que se abre. Esa
     carpeta ahora se encuentra en el directorio de configuración de plugins de OBS, así que tus deck lists sobreviven
     a las actualizaciones y reinstalaciones del plugin.
   - **Minimum Out of Screen Time**: el tiempo mínimo que debe pasar para que una carta recién detectada pueda volver
     a mostrarse.
   - **Minimum Screen Time**: el tiempo mínimo que se muestra una carta.
   - **Confidence Threshold**: define el nivel de confianza mínimo para la detección de cartas. Las detecciones por
     debajo de este umbral se ignorarán.
3. El plugin proporciona una nueva fuente llamada `Draw Display`. Puedes añadirla a tu escena como cualquier otra
   fuente. Esta fuente mostrará las cartas detectadas en pantalla. Puedes elegir de qué fuente/escena detectar las
   cartas.

   Esta fuente también permite ajustar con precisión lo que el detector ve realmente. Estas opciones están
   **desactivadas por defecto**; activa las que necesites desde los ajustes de Draw 2 (icono de engranaje), en el
   grupo *Funciones avanzadas*, y entonces aparecerán en las propiedades de la fuente:
   - **Detector / Player**: a qué jugador (1 o 2) alimenta esta fuente, para poder ejecutar un detector por jugador al
     mismo tiempo.
   - **Crop — Left / Top / Right / Bottom**: píxeles que se recortan de cada borde para centrar la detección en una
     región de la captura, sin afectar a la fuente en otros lugares.
   - **Rotate input 180°**: gira la entrada capturada antes de enviarla al detector (útil cuando la cámara está
     montada al revés).

   > 💡 El plugin también puede ofrecer una fuente **`DRAW Input Preview`** que muestra exactamente lo que recibe el
   > detector (la entrada recortada/rotada del jugador seleccionado). Está **desactivada por defecto**: actívala en los
   > ajustes de Draw 2 (*Funciones avanzadas*) y reinicia OBS, y luego añádela a una escena de pruebas para afinar el
   > recorte y el encuadre sin tocar la salida en directo `Draw Display`.

   > 💡 El plugin también puede cargar una deck list desde una **URL HTTP(S)** en lugar de un archivo `.ydk` local —
   > muy útil cuando tu lista de cartas la sirve una API remota o un sistema de gestión de torneos. Está
   > **desactivada por defecto** — activa **Enable remote decklist** en los ajustes de Draw 2 (*Funciones avanzadas*).
   >
   > Una vez activada, hay dos modos disponibles:
   > - **Import deck from URL…** (botón en los ajustes) — descarga la URL una sola vez y guarda el resultado como
   >   un `.ydk` normal en la carpeta de deck lists; luego puedes seleccionarlo como cualquier otro archivo.
   > - **Campos de URL por ranura** — una URL opcional por ranura de deck (3 ranuras × 2 jugadores). Si se configura,
   >   la URL se descarga en vivo al pulsar Start Draw y reemplaza el archivo seleccionado para esa ranura; ante
   >   cualquier error, el plugin recurre automáticamente al archivo elegido.
   >
   > Formatos de respuesta aceptados del servidor: array JSON de IDs de carta (passcodes); objeto JSON
   > `{ "main": [...], "extra": [...], "side": [...] }`; texto `.ydk` sin procesar; o texto plano con IDs numéricos.
   >
   > Se puede configurar una cabecera de autenticación opcional (nombre + valor, p. ej. `Authorization` /
   > `Bearer …`) que se envía con cada solicitud.
   >
   > ⚠️ Las URLs y el valor de la cabecera se almacenan en texto plano en QSettings, igual que el resto de ajustes
   > del plugin — evita guardar secretos de larga duración ahí.

4. Haz clic en el botón `Start DRAW` para iniciar el proceso de detección. El plugin empezará a detectar cartas en
   tiempo real y a mostrarlas en pantalla mediante la fuente `Draw Display`. El plugin comienza a detectar en el
   momento en que ves el botón `Stop DRAW`. Si no lo ves, algo salió mal.
5. En caso contrario, ¡disfruta del plugin!

Aquí tienes una pequeña vista previa :)

<div align="center">
    <img src="https://raw.githubusercontent.com/HichTala/draw2/refs/heads/main/figures/overview.gif" width="960" height="540" />
</div>

---

## <div align="center">🔍 Descripción del método</div>

Se ha publicado un artículo en Medium que explica el proceso principal, desde la recopilación de datos hasta la
predicción final. Puedes leerlo en
[esta](https://medium.com/@hich.tala.phd/how-i-trained-again-my-model-to-detect-and-recognise-a-wide-range-of-yu-gi-oh-cards-5c567a320b0a)
dirección. Si tienes cualquier pregunta, no dudes en abrir una issue.

[![Medium](https://img.shields.io/badge/-Medium-12100E?style=flat&logo=medium&labelColor=555)](https://medium.com/@hich.tala.phd/how-i-trained-again-my-model-to-detect-and-recognise-a-wide-range-of-yu-gi-oh-cards-5c567a320b0a)

---

## <div align="center">💬 Contacto</div>

Puedes contactarme en Twitter [@hichtala](https://twitter.com/hichtala) o por correo
en [hich.tala.phd@gmail.com](mailto:hich.tala.phd@gmail.com).

---

## <div align="center">⭐ Historial de Stars</div>

<div align="center">
  <a href="https://www.star-history.com/#hichtala/draw2&type=date&legend=top-left">
    <picture>
      <source media="(prefers-color-scheme: dark)" srcset="https://api.star-history.com/svg?repos=hichtala/draw2&type=date&theme=dark&legend=top-left" />
      <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/svg?repos=hichtala/draw2&type=date&legend=top-left" />
      <img alt="Star History Chart" src="https://api.star-history.com/svg?repos=hichtala/draw2&type=date&legend=top-left" />
    </picture>
  </a>
</div>
