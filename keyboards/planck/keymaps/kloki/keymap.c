/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _WORKMAN,
  _LOWER,
  _RAISE,
};

enum planck_keycodes {
  BACKLIT = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define WORKMAN PDF(_WORKMAN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Workman
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |Bspc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ct/Esc|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Sft/" |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |'/Sft |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  | Left |Gui/Rt|Lwr/Sp| Rai  | Ra/D |  Up  |   [  |   ]  |Lower |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT_planck_grid(
    KC_TAB,         KC_Q,    KC_D,    KC_R,    KC_W,             KC_B,              KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_BSPC,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_H,    KC_T,             KC_G,              KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_ENT,
    LSFT_T(KC_DQT), KC_Z,    KC_X,    KC_M,    KC_C,             KC_V,              KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
    KC_LCTL,        KC_LALT, KC_LGUI, KC_LEFT, LT(RAISE,KC_RIGHT), LT(LOWER, KC_SPC), LGUI_T(KC_BSPC), LT(RAISE, KC_DOWN), KC_UP, KC_LBRC, KC_RBRC, MO(LOWER)
),


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   {  |   }  |   ^  |   &  |      |  Up  |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   #  |   $  |   (  |   )  |   `  |   '  | Left | Down |Right |      | |    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   %  |   =  |   [  |   ]  |   =  |   -  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_CIRC, KC_AMPR, _______, KC_UP,   _______, _______, KC_DEL,
    KC_DEL,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_QUOT, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_PIPE,
    _______, KC_PERC, KC_EQL,  KC_LBRC, KC_RBRC, KC_EQL,  KC_MINS, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      | S(1) | S(2) | S(3) | S(4) | S(5) | S(6) | S(7) | S(8) | S(9) | S(0) |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |   ~  |  S(' |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |   +  |   _  |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_low(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          gpio_write_pin_high(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLD);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLU);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
