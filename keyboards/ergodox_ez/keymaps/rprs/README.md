# Notes to myself.

## Useful links

* Repo: https://github.com/rprs/qmk_firmware/tree/master
* Docs: https://docs.qmk.fm/#/
* Tutorial to flash: https://docs.qmk.fm/#/newbs
* Explanation of layers: https://docs.qmk.fm/#/keymap
* Full list of keycodes: https://docs.qmk.fm/#/keycodes
* Possible solution for audio keys not working: https://github.com/qmk/qmk_firmware/issues/11572

## To make changes

_tl,dr:_ `cd ~/src/qmk_firmware && qmk compile && qmk flash`.

* Make changes to your keymap: `~/src/qmk_firmware/keyboards/ergodox_ez/keymaps/rprs/keymap.c`.
* Cd into the repo dir: `cd ~/src/qmk_firmware/`.
* Compile your thing: `qmk compile -kb ergodox_ez -km rprs`.
  * Since you already set your default keyboard and keymap (see `qmk config`), just do `qmk compile`.
* Flash it! `qmk flash` (will ask to press the teensy key at one point).

