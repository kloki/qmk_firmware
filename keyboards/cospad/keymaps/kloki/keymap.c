#include "cospad.h"
#include "led.h"

#ifdef RGBLIGHT_ENABLE
#include "rgblight.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FUNC 1
#define _KEYS 2


#define _______ KC_TRNS


enum custom_keycodes {
    MXRE = SAFE_RANGE,
    MXBL,
    MXBR,
    MXCL,
    MXGR,
    MXBU,
    MXWH,
    MXGE,
    KSGO,
    KSBR,
    KSSI,
    KSCO,
    KSPI,
    KBRE,
    KBBL,
    KBWH,
    KBBR,
    ZEAL,
    HAKO,
    NKJA,
    NKPB,
    NKNA,
    NKBO,
    NKYE
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_BASE] = KEYMAP(
  KC_0,     KC_1,     KC_4,      KC_7, \
  MO(_FUNC),KC_2,     KC_5,      KC_8, \
  KC_SPC,   KC_3,     KC_6,      KC_9,  \
  KC_LEFT,  KC_ENTER, KC_TAB,    KC_BSPC, \
  KC_DOWN,  KC_UP,    KC_END,    KC_HOME, \
  KC_RGHT,  MO(_FUNC),KC_PGDOWN,  KC_PGUP),

[_FUNC] = KEYMAP(
  _______,  _______,  _______,  RESET,   \
  _______,  _______,  TG(_KEYS),_______, \
  _______,  _______,  _______,  _______, \
  RGB_RMOD, _______,  _______,  KC_DEL , \
  RGB_HUD,  RGB_HUI,  _______,  _______, \
  RGB_MOD,  _______,  _______,  _______),

[_KEYS] = KEYMAP(
  KSGO,KSBR,ZEAL,HAKO, \
  KSCO,KSPI,NKJA,MXBR, \
  KSSI,NKBO,NKNA,MXCL, \
  KBRE,NKPB,KBWH,MXBL, \
  KBBR,NKYE,KBBL,MXWH, \
  MXBL,MXGE,MXRE,MXGR),
};


void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    switch (layer) {
        case _KEYS:
            rgblight_sethsv(240, 255, 255);
            break;
        default:
            // none
            break;
    }
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case MXRE:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Red, linear with a light spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXBL:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Black linear with a medium spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXBR:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Brown, tactile with a light spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXCL:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Clear, bigger tactile with a medium spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXGR:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Grey, bigger tactile with a heavy spring"SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXBU:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Blue, click slider with high hysteresis, with light spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXWH:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX White, click slider with high hysteresis, with medium/heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case MXGE:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Green, click slider with high hysteresis, with heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KSGO:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Gold, short travel, click slider."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KSBR:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Bronze, short travel, clickbar."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KSSI:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Silver, short travel, linear."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;

      case KSCO:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Copper, short travel, tactile."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KSPI:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Pink, short travel, clickbar."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KBRE:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Red, dust resistant, linear, light spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KBBL:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Black, dust resistant, linear, medium spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KBWH:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box White, dust resistant, click bar, medium spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case KBBR:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Brown, dust resistant, tactile, light spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case ZEAL:
         if (record->event.pressed) {
             SEND_STRING("Zealios 80gr, extra tactile, extra smooth, heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case HAKO:
         if (record->event.pressed) {
             SEND_STRING("Input Club Hako Clear, high tactile, heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case NKJA:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Jade, thick clickbar, medium spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case NKPB:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Pale Blue, clickbar, heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case NKNA:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Navy, thick clickbar, heavy spring"SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;
      case NKBO:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Brunt Orange, tactile, heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false; 
      case NKYE:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Yellow, linear, heavy spring."SS_TAP(X_ENTER));
             layer_off(_KEYS);
             layer_off(_FUNC);
         }
         return false;


      default:
         return true;
   }
}
