#pragma message "You may need to add LAYOUT_planck_grid to your keymap layers - see default for an example"
#include "planck.h"
#include "action_layer.h"
extern keymap_config_t keymap_config;

enum planck_layers {
  _WORKMAN,
  _QWERTY,
  _NUM,
  _SYM,
  _FUN
};

enum planck_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_WORKMAN] = {
  {KC_TAB,        KC_Q,    KC_D,    KC_R,    KC_W,   KC_B,    KC_J,    KC_F,   KC_U,    KC_P,    KC_SCLN, KC_BSPC },
  {CTL_T(KC_ESC), KC_A,    KC_S,    KC_H,    KC_T,   KC_G,    KC_Y,    KC_N,   KC_E,    KC_O,    KC_I,    KC_ENT  },
  {KC_LSFT,       KC_Z,    KC_X,    KC_M,    KC_C,   KC_V,    KC_K,    KC_L,   KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT },
  {MO(_FUN),      KC_LGUI, KC_LALT, KC_LEFT, LT(_NUM,KC_RGHT),LT(_SYM,KC_SPC),  LT(_SYM,KC_SPC), LGUI_T(KC_DOWN),KC_UP,   KC_LBRC, KC_RBRC, MO(_SYM)}
},


[_QWERTY] = {
  {_______, KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    _______},
  {_______, KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN, _______},
  {_______, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, _______},
  {_______, _______, _______, _______, _______,_______,_______,_______,_______,_______, _______, _______}
},


[_NUM] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BTN1, KC_MS_U, KC_BTN2, _______, _______},
  {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MS_L, KC_MS_D, KC_MS_R, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


[_SYM] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_ASTR, KC_CIRC, KC_AMPR, KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL },
  {KC_DEL,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_MINS, KC_UNDS, KC_PLUS,  KC_EQL,  KC_BSLS, _______},
  {_______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR, KC_LABK, KC_RABK,  KC_HOME, KC_END,  KC_PIPE},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,}
},




/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |   T  |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|      |      |Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FUN] = {
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL },
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  _______, _______, QWERTY,  WORKMAN, _______, _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}
};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
