# Notes to myself.

## Useful links

* Repo: https://github.com/rprs/qmk_firmware/tree/master
* Docs: https://docs.qmk.fm/#/
* Tutorial to flash: https://docs.qmk.fm/#/newbs
* Explanation of layers: https://docs.qmk.fm/#/keymap
* Full list of keycodes: https://docs.qmk.fm/#/keycodes
* Docs into combos (though layers currently do the work for me): https://docs.qmk.fm/#/feature_combo?id=combos
* How to clean keycaps: https://help.corsair.com/hc/en-us/articles/360059094911-Tips-on-cleaning-your-keycaps-and-keyboard

## To make changes

_tl,dr:_ `cd ~/src/qmk_firmware && qmk compile && qmk flash`.

* Make changes to your keymap: `~/src/qmk_firmware/keyboards/ergodox_ez/keymaps/rprs/keymap.c`.
* Cd into the repo dir: `cd ~/src/qmk_firmware/`.
* Compile your thing: `qmk compile -kb ergodox_ez -km rprs`.
  * Since you already set your default keyboard and keymap (see `qmk config`), just do `qmk compile`.
* Flash it! Run `qmk flash` (will ask to press the teensy key at one point).

##  About the audio issue (media keys not working)

This was a linux issue, not the keyboard.

* Issue raised with the firmware: https://github.com/qmk/qmk_firmware/issues/11572
* Good explanation of the issue: https://unix.stackexchange.com/questions/439486/how-can-i-make-media-keys-work-with-i3
* My actual solution (install volumeicon-alsa): https://www.reddit.com/r/i3wm/comments/4s0aev/how_to_add_volume_control_applet_to_status_bar/
* Searches I did for this:
  * How to enable my keyboard's volume keys in i3
  * i3 gnome audio
  * audio applet i3

## About Miryoku layout (36 keys, for keyboards like corne).

* Source: https://github.com/manna-harbour/miryoku?tab=readme-ov-file
* Announcement in reddit: https://www.reddit.com/r/ErgoDoxEZ/comments/ijtcq1/miryoku_layout_for_moonlander_planck_ez_and/
* His/Her official layouts
  * https://configure.ergodox-ez.com/ergodox-ez/layouts/Ee9mD/latest/3
  * https://configure.ergodox-ez.com/planck-ez/layouts/9wKxx/latest/4
* Other layouts inspired by it.
  * Robin's compact https://configure.zsa.io/moonlander/layouts/xDpMW/latest/0/combos/list
  * Ronini's (inspired by robin's compcat, what Nevin uses): https://configure.zsa.io/voyager/layouts/D5lOq/latest/0

## Cool features from qmk to try.

Good thread for inspiration: https://www.reddit.com/r/olkb/comments/t4imri/qmk_tricks/

* international keys (áéíóúñ).
* permissive hold for home mods.
* cap words?
* vim layer?
* word selection?
* macros?
  * web search word under cursor.
  * join lines
* leader key?

