/* Copyright 2021 Jose Luis Adelantado Torres
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

#ifdef OLED_ENABLE
#    include "oled_display.h"
#endif

enum layer_names { _MA, _FN1, _FN2, _NL };

enum custom_keycodes {
    KC_CUST = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MA] = LAYOUT_iso(
             KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    KC_ESC,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_HOME,
    KC_ESC,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGUP,
    TG(_NL),  KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
    KC_SLCK,  KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    MO(_FN1), MO(_FN2), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_FN1] = LAYOUT_iso(
               RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_INS,
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______,   KC_INS, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,                            _______,                   _______, _______, _______, KC_HOME, _______, KC_END
  ),
  [_FN2] = LAYOUT_iso(
               RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_HOME,  KC_INS,
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
 ),
  [_NL] = LAYOUT_iso(
             _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_7,   KC_8,   KC_9,  KC_0,  KC_MINS,  KC_EQL, KC_BSPC,  KC_INS,
    RGB_TOG, _______, _______, _______, _______, _______, _______, _______, KC_4,   KC_5,   KC_6,  _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_1,   KC_2,   KC_3,  _______, _______, _______, _______, _______,
    KC_TRNS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
 ),

};
// clang-format off
// clang-format on

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    oled_timer = timer_read32();
    set_oled_mode(OLED_MODE_IDLE);
    return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (timer_elapsed(oled_timer) >= 3000) {
        set_oled_mode(OLED_MODE_IDLE);
    }
    render_frame();
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Send keystrokes to host keyboard, if connected (see readme)
    process_record_remote_kb(keycode, record);

    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
#ifdef OLED_ENABLE
                process_record_keymap_oled(keycode);
#endif
            }
            break;
        case KC_CUST:  // custom macro
            if (record->event.pressed) {
            }
            break;
    }
    return true;
}

// RGB config, for changing RGB settings on non-VIA firmwares
void change_RGB(bool clockwise) {
    bool shift = get_mods() & MOD_MASK_SHIFT;
    bool alt = get_mods() & MOD_MASK_ALT;
    bool ctrl = get_mods() & MOD_MASK_CTRL;

    if (clockwise) {
        if (alt) {
            rgblight_increase_hue();
        } else if (ctrl) {
            rgblight_increase_val();
        } else if (shift) {
            rgblight_increase_sat();
        } else {
            rgblight_step();
        }

  } else {
      if (alt) {
            rgblight_decrease_hue();
        } else if (ctrl) {
            rgblight_decrease_val();
        } else if (shift) {
            rgblight_decrease_sat();
        } else {
            rgblight_step_reverse();
        }
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (layer_state_is(1)) {
        //change RGB settings
        change_RGB(clockwise);
    }
    else {
        if (clockwise) {
            tap_code(KC_VOLU);
            process_record_encoder_oled(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
            process_record_encoder_oled(KC_VOLD);
        }
    }
    return true;
}

void matrix_init_user(void) {
    // Initialize remote keyboard, if connected (see readme)
    matrix_init_remote_kb();
}

void matrix_scan_user(void) {
    // Scan and parse keystrokes from remote keyboard, if connected (see readme)
    matrix_scan_remote_kb();
}
