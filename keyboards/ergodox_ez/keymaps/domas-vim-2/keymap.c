#include QMK_KEYBOARD_H
#include "version.h"
}

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ergodox_pretty_80(
    LCTL(LWIN(KC_LEFT)), KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV,      KC_PPLS, KC_QUOT, KC_6, KC_7, KC_8, KC_9, LCTL(LWIN(KC_RIGHT)), 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,                  KC_BSLS, KC_SLSH, KC_Y, KC_U, KC_I, KC_O, KC_P, 
    LT(1,KC_EQL), KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_COLN, 
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCBR,                 KC_UNDS, KC_RCBR, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSPC, 
    KC_LCTL, KC_NO, KC_NO, KC_LALT, KC_LGUI,                        KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, 

			  KC_F12, KC_NO,                                              TG(4), KC_NO, 
				KC_PAST, KC_MINS, KC_DQUO,                                  MO(2), KC_LT, KC_GT, 
				KC_SPC, KC_BSPC, MO(3),                                     KC_RCTL, KC_ESC, KC_ENT
),

[1] = LAYOUT_ergodox_pretty_80(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_DOT, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 

        KC_NO, KC_NO,                                       KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO,                                KC_TRNS, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO,                                KC_NO, KC_0, KC_NO
),


[2] = LAYOUT_ergodox_pretty_80(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,               KC_NO, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                                                                                                                    
    KC_NO, KC_NO,                                           KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO,                                    KC_TRNS, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO

),

[3] = LAYOUT_ergodox_pretty_80(
    KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_NO,        KC_NO, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_NO, KC_LT, KC_MINS, KC_EQL, KC_GT, KC_NO, KC_NO,     KC_NO, KC_NO, KC_ASTR, KC_PLUS, KC_DQUO, KC_PIPE, KC_SCLN,
	  KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO, KC_CIRC, KC_SLSH, KC_QUES, KC_UNDS, KC_QUOT, 
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_BSLS, KC_AMPR, KC_GRV, KC_TILD, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                                                                       
    KC_NO, KC_NO,                                           KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_NO,                                    KC_NO, KC_NO, KC_NO, 
    KC_NO, KC_NO, KC_TRNS,                                  KC_NO, KC_NO, KC_NO
),

[4] = LAYOUT_ergodox_pretty_80(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,       KC_NO, KC_NO, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LSFT,          KC_NO, KC_NO, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_1, KC_A, KC_S, KC_D, KC_F, KC_G,                     KC_NO, KC_H, KC_J, KC_K, KC_L, KC_COLN, 
    KC_2, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC,             KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT,
    KC_3, KC_4, KC_5, KC_6, KC_7,                           KC_NO, KC_RALT, KC_RGUI, KC_APP, KC_RCTL,
                                                                                                                
    KC_SPC, KC_BSPC,                                        KC_TRNS, KC_NO,
    KC_H, KC_J, KC_K,                                       KC_NO, KC_NO, KC_NO,
    KC_8, KC_9, KC_0,                                       KC_NO, KC_NO, KC_ENT
),
};

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
