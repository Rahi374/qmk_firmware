#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _DVORAK 1
#define _GAMING 2
#define _FFXIV 3
#define _LOWER 4
#define _RAISE 5
#define _MOUSE 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  GAMING,
  FFXIV,
  LOWER,
  RAISE,
  MOUSE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Mouse |AltGr | Alt  | GUI  |Lower |Space |Raise |SpCtrl| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *
 * Have to figure out how to do the compose key
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  MOUSE,   KC_ALGR, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   RCTL_T(KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   /  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Mouse |AltGr | Alt  | GUI  |Lower |Space |Raise | Ctrl | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_SLSH, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_ENT, \
  KC_LSPO, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSPC , \
  MOUSE,   KC_ALGR, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  RAISE,   RCTL_T(KC_SPC), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Gaming (Qwerty with space and arrow keys moved)
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Mouse |AltGr | Alt  | GUI  |Space |Lower |Raise |SpCtrl|   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 *
 * Have to figure out how to do the compose key
 */
[_GAMING] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSPC, \
  MOUSE,   KC_ALGR, KC_LALT, KC_LGUI, KC_SPC,  LOWER,   RAISE,   RCTL_T(KC_SPC), KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* FFXIV
 * ,-----------------------------------------------------------------------------------.
 * |  Esc |  F1  |  F2  |  F3  |  F4  |  F5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Shift(|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  /   |Shift)|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | CAS  |  CA  |  AS  |  CS  |Space |Lower |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_FFXIV] = LAYOUT( \
  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC, \
  KC_LALT, C(S(KC_LALT)), C(KC_LALT), S(KC_LALT), C(KC_LSHIFT), KC_SPC,  LOWER,   RAISE,   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |Pause |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PrScr | Esc  |   `  | Home | PgUp |  F11 |   [  |   ]  |   -  |   =  | Bksp | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |   ~  | End  | PgDn |  F12 | Left | Down |  Up  |Right |   '  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   `  | Menu |      |   {  |   }  |   _  |   +  |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | Stop | Prev | Next |      |             | Mute | Vol- | Vol+ | Bri- | Bri+ |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PAUS, \
  KC_PSCR, KC_ESC,  KC_GRV,  KC_HOME, KC_PGUP, KC_F11,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, \
  _______, _______, KC_TILD, KC_END,  KC_PGDN, KC_F12,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_DQUO, \
  _______, _______, _______, KC_GRV,  KC_APP,  _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_PIPE, _______, \
  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |Pause |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |PrScr | Esc  |CSPgUp|SPgUp |CPgUp |  F11 |   [  |   ]  |   -  |   =  | Bksp | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |CSPgDn|SPgDn |CPgDn |  F12 | Left | Down |  Up  |Right |   '  |   "  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |   `  | Menu |      |   {  |   }  |   _  |   +  |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Play | Stop | Prev | Next |      |             | Mute | Vol- | Vol+ | Bri- | Bri+ |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PAUS, \
  KC_PSCR, KC_ESC,  C(S(KC_PGUP)), S(KC_PGUP), C(KC_PGUP), KC_F11, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSPC, KC_DEL, \
  _______, _______, C(S(KC_PGDN)), S(KC_PGDN), C(KC_PGDN), KC_F12, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, KC_DQUO, \
  _______, _______, _______, KC_GRV,  KC_APP,  _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_PIPE, _______, \
  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU \
),

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Lclick| MUP  |Rclick|Mclick|      |Lclick|Rclick|  Wup |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |MLEFT |MDOWN |MRIGHT|      |      |Mclick|Wleft |Wdown |Wright|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3, _______, KC_BTN1, KC_BTN2, KC_WH_U, _______, _______, _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, KC_BTN3, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | RGBup|      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |  RGB |Qwerty|      |Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Gaming|FFXIV |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  _______, _______, _______, _______, _______, _______, RGB_VAI, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, _______, _______, _______, RGB_TOG, QWERTY,  _______, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, GAMING,  FFXIV,   _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
  //rgblight_sethsv(255, 66, 61);
  rgblight_setrgb_range(0x69, 0x35, 0x9c, 0, 24);
  rgblight_set();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed)
        persistent_default_layer_set(1UL<<_QWERTY);
      return false;
      break;
    case DVORAK:
      if (record->event.pressed)
        persistent_default_layer_set(1UL<<_DVORAK);
        return false;
	break;
    case GAMING:
      if (record->event.pressed)
        persistent_default_layer_set(1UL<<_GAMING);
        return false;
	break;
    case FFXIV:
      if (record->event.pressed)
        persistent_default_layer_set(1UL<<_FFXIV);
        return false;
	break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case MOUSE:
      if (record->event.pressed) {
        layer_on(_MOUSE);
      } else {
        layer_off(_MOUSE);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
