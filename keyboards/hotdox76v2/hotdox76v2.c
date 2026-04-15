// Copyright 2021 JasonRen(biu)
// Copyright 2022 Drashna Jael're (@Drashna Jael're)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "hotdox76v2.h"
#include "oled_font_lib/logo2.h"
#include "oled_font_lib/ext_font.h"

#ifdef OLED_ENABLE

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    if (is_keyboard_left()) {
        return OLED_ROTATION_180;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_logo(void) {
    uint8_t i = 0, j = 0;
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 32; ++j) {
            if (is_keyboard_left()) {
                oled_write_raw_byte(pgm_read_byte(&logo_mouse[i * 32 + j]), i * 128 + j);
            } else {
                oled_write_raw_byte(pgm_read_byte(&logo_mouse[i * 32 + j]), i * 128 + j + 96);
            }
        }
    }
}

void render_layer_helper_fun(uint8_t start_line, const char *data, uint8_t gap_w, uint8_t l) {
    uint8_t j = 0, k = 0;
    for (j = 0; j < l; ++j) {      // font index
        for (k = 0; k < 12; ++k) { // font byte index
            //                                        base + logo_w(32) + gap_w(12) +l*font_w(12)+current_byte_index
            oled_write_raw_byte(pgm_read_byte(&ext_big_font[pgm_read_byte(&data[j]) - 0x20][k]), start_line * 2 * 128 + 32 + gap_w + j * 12 + k);
            oled_write_raw_byte(pgm_read_byte(&ext_big_font[pgm_read_byte(&data[j]) - 0x20][k + 12]), start_line * 2 * 128 + 128 + 32 + gap_w + j * 12 + k);
        }
    }
    for (j = 0; j < gap_w; ++j) {
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 32 + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 32 + gap_w + l * 12 + j);

        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + 32 + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + 32 + gap_w + l * 12 + j);
    }
}
void render_layer(uint8_t layer) {
    render_layer_helper_fun(0, PSTR("LAYER:"), 12, 6);
    switch (layer) {
        case 0:
            render_layer_helper_fun(1, PSTR("WRKMAN"), 12, 6);
            break;
        case 1:
            render_layer_helper_fun(1, PSTR("QWERTY"), 12, 6);
            break;
        case 2:
            render_layer_helper_fun(1, PSTR("SYMBOL"), 12, 6);
            break;
        case 3:
        default:
            render_layer_helper_fun(1, PSTR("FUNC  "), 12, 6);
            break;
    }
}

void render_rgb_helper_fun(uint8_t start_line, const char *data, uint8_t gap_w, uint8_t l) {
    uint8_t j = 0, k = 0;
    for (j = 0; j < l; ++j) {      // font index
        for (k = 0; k < 12; ++k) { // font byte index
            oled_write_raw_byte(pgm_read_byte(&ext_big_font[pgm_read_byte(&data[j]) - 0x20][k]), start_line * 2 * 128 + gap_w + j * 12 + k);
            oled_write_raw_byte(pgm_read_byte(&ext_big_font[pgm_read_byte(&data[j]) - 0x20][12 + k]), start_line * 2 * 128 + 128 + gap_w + j * 12 + k);
        }
    }
    for (j = 0; j < gap_w; ++j) {
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + gap_w + l * 12 + j);

        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + j);
        oled_write_raw_byte(pgm_read_byte(&blank_block), start_line * 2 * 128 + 128 + gap_w + l * 12 + j);
    }
}

void render_rgb_mode(void) {
    render_rgb_helper_fun(0, PSTR("MATRIX:"), 6, 7);
    if (!rgb_matrix_is_enabled()) {
        render_rgb_helper_fun(1, PSTR("OFF    "), 6, 7);
        return;
    }
    switch (rgb_matrix_get_mode()) {
        case RGB_MATRIX_NONE:
            render_rgb_helper_fun(1, PSTR("OFF    "), 6, 7);
            break;
        case RGB_MATRIX_SOLID_COLOR:
            render_rgb_helper_fun(1, PSTR("SOLID  "), 6, 7);
            break;
        case RGB_MATRIX_GRADIENT_UP_DOWN:
            render_rgb_helper_fun(1, PSTR("GRDNT  "), 6, 7);
            break;
        case RGB_MATRIX_BREATHING:
            render_rgb_helper_fun(1, PSTR("BREATH "), 6, 7);
            break;
        case RGB_MATRIX_HUE_WAVE:
            render_rgb_helper_fun(1, PSTR("WAVE   "), 6, 7);
            break;
        case RGB_MATRIX_CYCLE_LEFT_RIGHT:
            render_rgb_helper_fun(1, PSTR("L/R    "), 6, 7);
            break;
        case RGB_MATRIX_CYCLE_OUT_IN:
            render_rgb_helper_fun(1, PSTR("IN/OUT "), 6, 7);
            break;
        case RGB_MATRIX_CYCLE_SPIRAL:
            render_rgb_helper_fun(1, PSTR("SPIRAL "), 6, 7);
            break;
        case RGB_MATRIX_RAINBOW_BEACON:
            render_rgb_helper_fun(1, PSTR("RAINBOW"), 6, 7);
            break;
        case RGB_MATRIX_RAINDROPS:
            render_rgb_helper_fun(1, PSTR("RAIN   "), 6, 7);
            break;
        case RGB_MATRIX_PIXEL_FRACTAL:
            render_rgb_helper_fun(1, PSTR("PIXEL  "), 6, 7);
            break;
        case RGB_MATRIX_TYPING_HEATMAP:
            render_rgb_helper_fun(1, PSTR("HEATMAP"), 6, 7);
            break;
        case RGB_MATRIX_STARLIGHT_SMOOTH:
            render_rgb_helper_fun(1, PSTR("STARTS "), 6, 7);
            break;
        case RGB_MATRIX_RIVERFLOW:
            render_rgb_helper_fun(1, PSTR("RIVER  "), 6, 7);
            break;
        default:
            render_rgb_helper_fun(1, PSTR("OTHER  "), 6, 7);
            break;
    }
}

bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
    render_logo();
    if (is_keyboard_left()) {
        render_layer(biton32(layer_state));
    } else {
        render_rgb_mode();
    }
    return false;
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case TOG_OLED:
            if (record->event.pressed) {
                if (is_oled_on()) {
                    oled_off();
                } else {
                    oled_on();
                }
            }
            return false;
        default:
            return true;
    }
    return true;
}

void keyboard_post_init_kb(void) {
    keyboard_post_init_user();
}

#endif

#ifdef SWAP_HANDS_ENABLE
__attribute__((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0,  6}, {1,  6}, {2,  6}, {3,  6}, {4,  6}, {5,  6}, {6, 6}},
    {{0,  7}, {1,  7}, {2,  7}, {3,  7}, {4,  7}, {5,  7}, {6,  7}},
    {{0,  8}, {1,  8}, {2,  8}, {3,  8}, {4,  8}, {5,  8}, {6,  8}},
    {{0,  9}, {1,  9}, {2,  9}, {3,  9}, {4,  9}, {5,  9}, {6,  9}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10},  {6, 10}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11},  {6, 11}},

    /* Right hand, matrix positions */
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
    {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}},
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}},
    {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}}
};
#endif
