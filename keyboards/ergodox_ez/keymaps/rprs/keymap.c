#include QMK_KEYBOARD_H
#include "version.h"
enum layers { BASE,
    FNKEYS,
    MOUSE,
    // Next 7 layers are Miryoku: https://github.com/manna-harbour/miryoku
    MIR_BASE,
    MIR_MEDIA, 
    MIR_NAV,
    MIR_MOUSE,
    MIR_SYM,
    // MIR_NUM Includes symbols not in MIR_SYM (I know, but can't think of a better name).
    MIR_NUM,
    MIR_FUN
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | Esc  |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Esc    |   Q  |   W  |   E  |   R  |   T  |  LS  |           |  LS  |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Tab    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| LGui |           |  \   |------+------+------+------+------+--------|
 * | LS     |   Z  |   X  |   C  |   V  |   B  |      |           | RGui |   N  |   M  |   ,  |   .  |   /  |   ]    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | +L3  | ~+L1 | ~+L2 |      | App  |                                       |  Lft |  Up  |  Dn  | Rght | ~+L2 |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LCtl | LAlt |       | RAlt | RCtl |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  Hm  |       | PgUp |      |      |
 *                                 | BkSp |  Del |------|       |------| Enter| Space|
 *                                 |      |      |  End |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand                                                              right hand
  KC_GRV,       KC_1,        KC_2,      KC_3,  KC_4,   KC_5, KC_ESC,        KC_EQL,          KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
  KC_ESC,       KC_Q,        KC_W,      KC_E,  KC_R,   KC_T, KC_LSFT,       KC_LSFT,         KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
  KC_TAB,       KC_A,        KC_S,      KC_D,  KC_F,   KC_G,                                 KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  KC_LSFT,      KC_Z,        KC_X,      KC_C,  KC_V,   KC_B, KC_LGUI,       RGUI_T(KC_BSLS), KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
  TG(MIR_BASE), TT(FNKEYS),  TT(MOUSE), KC_NO, KC_APP,                                             KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, TT(MOUSE),
                                                    KC_LCTL, KC_LALT,       KC_RALT, KC_RCTL,
                                                             KC_HOME,       KC_PGUP,
                                             KC_BSPC, KC_DEL, KC_END,       KC_PGDN, KC_ENT, KC_SPC
),

/* Keymap 1: Function Keys Layer
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Trans  |      |      |      |      |      |Trans |           |      |      |  F1  |  F2  |  F3  | F4   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Trans  |      |      |      |      |      |------|           |------|      |  F5  |  F6  |  F7  | F5   |  App   |
 * |--------+------+------+------+------+------|Trans |           |PtrScn|------+------+------+------+------+--------|
 * | Trans  |PtrScn|      |      |      |      |      |           |      |      |  F9  | F10  | F11  | F12  |  Menu  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Trans|      |      | LCtl | LAlt |                                       | Vol+ | Vol- | Mut  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Trans| Trans|       | Trans| Trans|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Trans|       | Trans|      |      |
 *                                 | Trans| Trans|------|       |------| Trans| Trans|
 *                                 |      |      | Trans|       | Trans|      |      |
 *                                 `--------------------'       `--------------------'
 */
[FNKEYS] = LAYOUT_ergodox_pretty(
  // left hand                                                        right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,          KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,        KC_TRNS,    KC_NO,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                             KC_NO,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_APP,
  KC_TRNS, KC_PSCR, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,        KC_PSCR,    KC_NO,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MENU,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT,                                            KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS,
                                             KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                      KC_TRNS,        KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |  -L2 |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Trans  |      |      |      |      |      |Trans |           |      |      | MwL  | MwD  | MwU  | MwR  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Trans  |      |      |      |      |      |------|           |------|      | McL  | McD  | McU  | McR  |        |
 * |--------+------+------+------+------+------|Trans |           |      |------+------+------+------+------+--------|
 * | Trans  |      |      |      |      |      |      |           |      |      |      |      |      | WFwd |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Trans| LGui |      | LCtl | LAlt |                                       | Vol+ | Vol- | Mut  | WBck |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Trans| Trans|       | Trans| Trans|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Trans|       |  Del |      |      |
 *                                 | Trans| Trans|------|       |------| Mb1  | Mb2  |
 *                                 |      |      | Trans|       |  Mb3 |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOUSE] = LAYOUT_ergodox_pretty(
  // left hand                                                        right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,          TT(MOUSE), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,        KC_TRNS,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                            KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_TRNS,
  KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,        KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_WFWD,   KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_LALT,                                            KC_MUTE, KC_VOLD, KC_VOLU, KC_WBAK, KC_TRNS,
                                             KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,
                                                      KC_TRNS,        KC_DEL,
                                    KC_TRNS, KC_TRNS, KC_TRNS,        KC_BTN3, KC_BTN1, KC_BTN2
),

/* Keymap 3: Miryoku Basic layer
 * Difference with original: I swapped quotes with colon (so qwerty resembles a normal keyboard).
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |LGUI/A|LALT/S|LCTL/D|LSFT/F|   G  |------|           |------|   H  |RSFT/J|RCTL/K|LALT/L|RGUI/;|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Trns |      |      |      |L4/Esc|                                       |L9/Tab|      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | L5/  |  L6/ |      |       |      | L7/  | L8/  |
 *                                 | BkSp |  Del |------|       |------| Enter| Space|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_BASE] = LAYOUT_ergodox_pretty(
  // TODO:
  // - Add LT(layer, kc) for activating each layer.


  // left hand                                                                                    right hand
  KC_NO,   KC_NO,        KC_NO,        KC_NO,        KC_NO,                 KC_NO, KC_NO,         KC_NO, KC_NO, KC_NO,               KC_NO,        KC_NO,        KC_NO,           KC_NO,
  KC_NO,   KC_Q,         KC_W,         KC_E,         KC_R,                  KC_T,  KC_NO,         KC_NO, KC_Y,  KC_U,                KC_I,         KC_O,         KC_P,            KC_NO,
  KC_NO,   LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),          KC_G,                        KC_H,  RSFT_T(KC_J),        RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_NO,
  KC_NO,   KC_Z,         KC_X,         KC_C,         KC_V,                  KC_B,  KC_NO,         KC_NO, KC_N,  KC_M,                KC_COMM,      KC_DOT,       KC_SLSH,         KC_NO,
  KC_TRNS, KC_NO,        KC_NO,        KC_NO,        LT(MIR_MEDIA, KC_ESC),                                     LT(MIR_FUN, KC_TAB), KC_NO,        KC_NO,        KC_NO,           KC_NO,
                                                                            KC_NO, KC_NO,         KC_NO, KC_NO,
                                                                                   KC_NO,         KC_NO,
                                      LT(MIR_NAV, KC_BSPC), LT(MIR_MOUSE, KC_DEL), KC_NO,         KC_NO, LT(MIR_SYM, KC_ENT), LT(MIR_NUM, KC_SPC)
),

/* Keymap 4: Miryoku Media and Board
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LGUI | LALT | LCTL | LSFT |      |------|           |------| Prev | Vol- | Vol+ | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | RALT |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | TRNS |                                       | Mute |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------| Stop | Play |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_MEDIA] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,                                      KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,        KC_NO, KC_NO,
                                                      KC_NO,        KC_NO,
                                        KC_NO, KC_NO, KC_NO,        KC_NO, KC_MSTP, KC_MPLY
),

/* Keymap 5: Miryoku Navigation.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | WBck |PrevTb|NextTb| WFwd |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LGUI | LALT | LCTL | LSFT |      |      |           |------| Left | Down |  Up  | Rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | RALT |      |      |      |      |           |      | Home | PgDn | PgUp | End  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | TRNS |      |------|       |------| Enter| Space|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_NAV] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,        KC_NO,       KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_WBAK, LCTL(KC_TAB), RCS(KC_TAB), KC_WFWD, KC_NO, KC_NO,
  KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_LEFT, KC_DOWN,      KC_UP,       KC_RGHT, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_HOME, KC_PGDN,      KC_PGUP,     KC_END,  KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_NO,       KC_NO,       KC_NO,   KC_NO, KC_NO,
                                               KC_NO, KC_NO,        KC_NO, KC_NO,
                                                      KC_NO,        KC_NO,
                                      KC_TRNS, KC_NO, KC_NO,        KC_NO, KC_ENT, KC_NO
),

/* Keymap 6: Miryoku Mouse.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | MwL  | MwD  | MwU  | MwR  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LGUI | LALT | LCTL | LSFT |      |      |           |------| McL  | McD  | McU  | McR  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | RALT |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  Mb3 |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      | TRNS |------|       |------|  Mb1 |  Mb2 |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_MOUSE] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_NO,   KC_NO,
  KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_NO, KC_NO,        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_BTN3, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,        KC_NO, KC_NO,
                                                      KC_NO,        KC_NO,
                                      KC_NO, KC_TRNS, KC_NO,        KC_NO, KC_BTN1, KC_BTN2
),

/* Keymap 7: Miryoku Symbos.
 * Difference with original: I swapped quotes with colon (so qwerty resembles a normal keyboard).
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  {   |  &   |  *   |  (   |  }   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  "   |  $   |  %   |  ^   |  +   |      |           |------|      | RSFT | RCTL | LALT | RGUI |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  ~   |  !   |  @   |  #   |  |   |      |           |      |      |      |      | RALT |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  _   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  (   |  )   |------|       |------| TRNS |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_SYM] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_DQT,  KC_DLR,  KC_PERC, KC_CIRC,  KC_PLUS,                    KC_NO, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_NO,
  KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS,                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,        KC_NO, KC_NO,
                                                      KC_NO,        KC_NO,
                                    KC_LPRN, KC_RPRN, KC_NO,        KC_NO, KC_TRNS, KC_NO
),

/* Keymap 8: Miryoku Numbers (and some symbols).
 * Difference with original: I added '+'. It felt weird not to have it with numbers. 
 *                           Location still tentative (trying to keep to the 36 keys limit).
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  [   |  7   |  8   |  9   |  ]   |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  '   |  3   |  5   |  6   |  =   |      |           |------|      | RSFT | RCTL | LALT | RGUI |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  `   |  1   |  2   |  3   |  \   |      |           |      |      | +    |      | RALT |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  -   |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  0   |  .   |------|       |------|      | TRNS |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_NUM] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_QUOT, KC_4,    KC_5,    KC_6,    KC_EQL,                     KC_NO, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_NO,
  KC_NO,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NO,      KC_NO, KC_NO, KC_PLUS, KC_NO,   KC_RALT, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MINS,                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,        KC_NO, KC_NO,
                                                      KC_NO,        KC_NO,
                                        KC_0, KC_DOT, KC_NO,        KC_NO, KC_NO, KC_TRNS
),

/* Keymap 9: Miryoku Function keys.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Teensy |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | F12  |  F7  |  F8  |  F9  |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F11  |  F4  |  F5  |  F6  |      |      |           |------|      | RSFT | RCTL | LALT | RGUI |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | F10  |  F1  |  F2  |  F3  |      |      |           |      |      |      |      | RALT |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Spc  |                                       | TRNS |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | App  | Tab  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MIR_FUN] = LAYOUT_ergodox_pretty(
  // left hand                                                      right hand
  QK_BOOT, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_F12,  KC_F7,  KC_F8,   KC_F9,   KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_F11,  KC_F4,  KC_F5,   KC_F6,   KC_NO,                      KC_NO, KC_RSFT, KC_RCTL, KC_LALT, KC_RGUI, KC_NO,
  KC_NO,   KC_F10,  KC_F1,  KC_F2,   KC_F3,   KC_NO,   KC_NO,      KC_NO, KC_NO, KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_SPC,                                     KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                                KC_NO, KC_NO,      KC_NO, KC_NO,
                                                       KC_NO,      KC_NO,
                                       KC_APP, KC_TAB, KC_NO,      KC_NO, KC_NO, KC_NO
), }; // clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    // reduce the brightness of the stauts leds (top right) to its minimum.
    ergodox_led_all_set(LED_BRIGHTNESS_LO);
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }
    return state;
};
