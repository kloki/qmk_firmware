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
#define _KEYS 1
#define _FUNC 2


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
  KC_DOT,   KC_2,     KC_5,      KC_8, \
  KC_SPC,   KC_3,     KC_6,      KC_9,  \
  KC_LEFT,  KC_ENTER, KC_TAB,    KC_BSPC, \
  KC_DOWN,  KC_UP,    KC_END,    KC_HOME, \
  KC_RGHT,  MO(_FUNC),KC_PGDOWN,  KC_PGUP),

[_KEYS] = KEYMAP(
  KSGO,KSBR,ZEAL,HAKO, \
  KSCO,KSPI,NKJA,MXBR, \
  KSSI,NKBO,NKNA,MXCL, \
  KBRE,NKPB,KBWH,MXBL, \
  KBBR,NKYE,KBBL,MXWH, \
  MXBL,LT(_FUNC, MXGR),MXRE,MXGR),

[_FUNC] = KEYMAP(
  _______,  _______,  _______,  RESET,   \
  _______,  _______,  _______,  BL_TOGG, \
  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  KC_DEL , \
  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  TG(_KEYS)),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case BL_TOGG:
         if (record->event.pressed) {
            cospad_bl_led_togg();
         }
      case MXRE:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Red"SS_TAP(X_ENTER));
         }
         return false;
      case MXBL:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Black"SS_TAP(X_ENTER));
         }
         return false;
      case MXBR:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Brown"SS_TAP(X_ENTER));
         }
         return false;
      case MXCL:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Clear"SS_TAP(X_ENTER));
         }
         return false;
      case MXGR:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Grey"SS_TAP(X_ENTER));
         }
         return false;
      case MXBU:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Blue"SS_TAP(X_ENTER));
         }
         return false;
      case MXWH:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX White"SS_TAP(X_ENTER));
         }
         return false;
      case MXGE:
         if (record->event.pressed) {
             SEND_STRING("Cherry MX Green"SS_TAP(X_ENTER));
         }
         return false;
      case KSGO:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Gold"SS_TAP(X_ENTER));
         }
         return false;
      case KSBR:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Bronze"SS_TAP(X_ENTER));
         }
         return false;
      case KSSI:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Silver"SS_TAP(X_ENTER));
         }
         return false;

      case KSCO:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Copper"SS_TAP(X_ENTER));
         }
         return false;      
      case KSPI:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Speed Pink"SS_TAP(X_ENTER));
         }
         return false;
      case KBRE:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Red"SS_TAP(X_ENTER));
         }
         return false;
      case KBBL:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Black"SS_TAP(X_ENTER));
         }
         return false;
      case KBWH:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box White"SS_TAP(X_ENTER));
         }
         return false;
      case KBBR:
         if (record->event.pressed) {
             SEND_STRING("Kaihl Box Brown"SS_TAP(X_ENTER));
         }
         return false;
      case ZEAL:
         if (record->event.pressed) {
             SEND_STRING("Zealios 80gr"SS_TAP(X_ENTER));
         }
         return false;
      case HAKO:
         if (record->event.pressed) {
             SEND_STRING("Input Club Hako Clear"SS_TAP(X_ENTER));
         }
         return false;
      case NKJA:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Jade"SS_TAP(X_ENTER));
         }
         return false;
      case NKPB:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Pale Blue"SS_TAP(X_ENTER));
         }
         return false;
      case NKNA:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box NAVY"SS_TAP(X_ENTER));
         }
         return false;
      case NKBO:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Brunt Orange"SS_TAP(X_ENTER));
         }
         return false; 
      case NKYE:
         if (record->event.pressed) {
             SEND_STRING("Novelkeys Box Yellow"SS_TAP(X_ENTER));
         }
         return false;


      default:
         return true;
   }
}
