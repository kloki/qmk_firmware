/* Copyright 2017 Wunder
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

enum layer_names {
    _WM,
    _QW,
    _SYM,
    _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WM] = LAYOUT_ortho_5x15( /* WORKMAN */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           TG(_QW), KC_HOME,MO(_FN),           KC_6,    KC_7,    KC_8,   KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,           KC_GRAVE,KC_END, KC_QUOT,           KC_J,    KC_F,    KC_U,   KC_P,    KC_SCLN, KC_BACKSLASH,
 LCTL_T(KC_ESC), KC_A,    KC_S,    KC_H,    KC_T,    KC_G,           KC_EQL,  KC_UP,  KC_MINS,           KC_Y,    KC_N,    KC_E,   KC_O,    KC_I,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,           KC_LEFT, KC_DOWN,KC_RIGHT,          KC_K,    KC_L,    KC_COMM,KC_DOT,  KC_SLSH, KC_QUOT,
        KC_LCTL, KC_LGUI, KC_LALT, KC_LEFT, KC_RIGHT,LT(_SYM,KC_SPC),LGUI_T(KC_ENTER),  KC_QUOT,LT(_SYM,KC_TAB), KC_BSPC, KC_DOWN, KC_UP,  KC_LBRC, KC_RBRC, MO(_SYM)
    ),

    [_QW] = LAYOUT_ortho_5x15( /* QWERTY */
     _______,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   _______, _______, _______, KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    _______ ,
     _______,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   _______, _______, _______, KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    _______ ,
     KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   _______, _______, _______, KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, _______ ,
     _______,  KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   _______, _______, _______, KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, _______ ,
     _______,  _______, _______, _______, _______,KC_SPC, _______, _______, _______, _______,_______,_______, _______, _______, _______
    ),


    [_SYM] = LAYOUT_ortho_5x15( /* QWERTY */
     _______,  _______, _______, _______, _______, _______,_______, _______, _______, _______,_______,_______,_______,_______, KC_DEL ,
     _______,  KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_ASTR,KC_TILD, _______, KC_DQT,  KC_LABK,_______,KC_UP  ,_______,_______,_______ ,
     _______,  KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_PIPE,KC_PLUS,_______, KC_UNDS, KC_RABK,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______ ,
     _______,  KC_PERC, KC_EQL,  KC_LBRC, KC_RBRC, KC_CIRC,_______,_______, _______, KC_AMPR,_______,_______,_______,_______,_______ ,
     _______,  _______, _______, _______, _______,_______,_______,  _______, _______, _______,_______,_______,_______,_______,_______
    ),

    [_FN] = LAYOUT_ortho_5x15( /* FUNCTION */
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,  QK_BOOT, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, UG_HUED, UG_HUEU, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, UG_SATD, UG_SATU, _______,  _______, _______, _______, _______, QK_BOOT, _______, _______, _______,
        _______, _______, _______, _______, UG_VALD, UG_VALU, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, UG_TOGG, _______, UG_PREV, UG_NEXT, _______,  _______, _______, _______, _______, _______, _______, _______, _______
    )
};
