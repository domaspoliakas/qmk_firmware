#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

enum {
    TD_QUOT_PLUS
};

void dquo_plus_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_DQUO);
    } else {
        SEND_STRING("\"+");
    }
}

void dquo_plus_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_DQUO);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for quot, twice for quot then +, three times for quot then + then y
    [TD_QUOT_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dquo_plus_finished, dquo_plus_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_ergodox_pretty_80(
    KC_LT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_GRV,                    KC_PPLS, KC_QUOT, KC_6, KC_7, KC_8, KC_9, KC_GT, 
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LBRC,                  KC_BSLS, KC_SLSH, KC_Y, KC_U, KC_I, KC_O, KC_P, 
    LT(1,KC_EQL), KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_RBRC, KC_H, KC_J, KC_K, KC_L, KC_COLN, 
    KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCBR,                 KC_UNDS, KC_RCBR, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSPC, 
    KC_LCTL, KC_GRV, KC_QUES, KC_LALT, KC_LGUI,                     KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_ENT, 

			  KC_F12, KC_NO,                                              TG(4), KC_NO, 
				KC_PAST, KC_MINS, KC_TILD,                                  MO(2), KC_CIRC, KC_DLR, 
				KC_SPC, KC_BSPC, MO(3),                                     TD(TD_QUOT_PLUS), KC_ESC, KC_ENT
),

[1] = LAYOUT_ergodox_pretty_80(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_7, KC_8, KC_9, _______, _______, 
    _______, _______, _______, _______, _______, _______,                        _______, KC_4, KC_5, KC_6, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_1, KC_2, KC_3, _______, _______, 
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, 

        _______, _______,                                               _______, _______, 
        _______, _______, _______,                                      _______, _______, _______, 
        _______, _______, _______,                                      _______, KC_0, _______
),


[2] = LAYOUT_ergodox_pretty_80(
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, 
    _______, _______, _______, _______, _______, _______,                        _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______, 
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, 
                                                                                                                    
    _______, _______,                                                   _______, _______, 
    _______, _______, _______,                                          _______, _______, _______, 
    _______, _______, _______,                                          _______, _______, _______

),

[3] = LAYOUT_ergodox_pretty_80(
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    _______, KC_LT, KC_MINS, KC_EQL, KC_GT, _______, _______,           _______, _______, KC_ASTR, KC_PLUS, KC_DQUO, KC_PIPE, KC_SCLN,
	  _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                           _______, KC_CIRC, KC_SLSH, KC_QUES, KC_UNDS, KC_QUOT, 
    _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_BSLS, KC_AMPR, KC_GRV, KC_TILD, _______,
    _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,
                                                                                                                       
    _______, _______,                                                   _______, _______, 
    _______, _______, _______,                                          _______, _______, _______, 
    _______, _______, _______,                                          _______, _______, _______
),

[4] = LAYOUT_ergodox_pretty_80(
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,       _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_LSFT,          _______, _______, KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_1, KC_A, KC_S, KC_D, KC_F, KC_G,                              _______, KC_H, KC_J, KC_K, KC_L, KC_COLN, 
    KC_2, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_SPC,             _______, _______, KC_N, KC_M, KC_COMM, KC_DOT, KC_RSFT,
    KC_3, KC_4, KC_5, KC_6, KC_7,                           _______, KC_RALT, KC_RGUI, KC_APP, KC_RCTL,
                                                                                                                
    KC_SPC, KC_BSPC,                                        _______, _______,
    KC_H, KC_J, KC_K,                                       _______, _______, _______,
    KC_8, KC_9, KC_0,                                       _______, _______, KC_ENT
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
        /* case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break; */
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        /* case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break; */
        default:
            break;
    }

    return state;
};
