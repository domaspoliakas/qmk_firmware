#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    TD_QUOT_PLUS,
    TD_EQ_NUMLAYER_ARROW
};

enum {
    L_DEFAULT,
    L_NUMS,
    L_MEDIA,
    L_SYMBOLS
};

td_state_t cur_dance(tap_dance_state_t *state);

void eq_numlayer_arrow_finished(tap_dance_state_t *state, void *user_data);
void eq_numlayer_arrow_reset(tap_dance_state_t *state, void *user_data);


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_DEFAULT] = LAYOUT_ergodox_pretty_80(
      KC_LT,                    KC_1,   KC_2,    KC_3,    KC_4,    KC_5, KC_GRV,      KC_PPLS, KC_QUOT, KC_6,      KC_7,         KC_8,    KC_9,    KC_GT,        
      KC_TAB,                   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,     KC_BSLS, KC_SLSH, KC_Y,      KC_U,         KC_I,    KC_O,    KC_P,         
      TD(TD_EQ_NUMLAYER_ARROW), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_RBRC, KC_H,      KC_J,         KC_K,    KC_L,    KC_COLN, 
      SC_LSPO,                  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LCBR,     KC_UNDS, KC_RCBR, KC_N,      KC_M,         KC_COMM, KC_DOT,  SC_RSPC,
      KC_LCTL,                  KC_GRV, KC_QUES, KC_LALT, KC_LGUI,                                      RGUI_T(KC_LEFT), RALT_T(KC_DOWN), KC_UP,   KC_RIGHT,   KC_RCTL,  

                                                           KC_F12,         KC_NO,     KC_NO,            KC_NO, 
                                                 KC_PAST, KC_MINS,       KC_TILD,     MO(L_MEDIA),      KC_CIRC, KC_DLR, 
                                                  KC_SPC, KC_BSPC, MO(L_SYMBOLS),     TD(TD_QUOT_PLUS), KC_ESC,  KC_ENT
  ),

  [L_SYMBOLS] = LAYOUT_ergodox_pretty_80(
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,                _______, _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
      _______, KC_LT, KC_MINS, KC_EQL, KC_GT, _______, _______,           _______, _______, KC_ASTR, KC_PLUS, KC_DQUO, KC_PIPE, KC_SCLN,
  	  _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                           _______, KC_CIRC, KC_SLSH, KC_QUES, KC_UNDS, KC_QUOT, 
      _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_BSLS, KC_AMPR, KC_GRV, KC_TILD, _______,
      _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______,

      _______, _______,                                                   _______, _______, 
      _______, _______, _______,                                          _______, _______, _______, 
      _______, _______, _______,                                          _______, _______, _______
  ),

  [L_NUMS] = LAYOUT_ergodox_pretty_80(
      _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, 
      _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_7, KC_8, KC_9, _______, _______, 
      _______, _______, _______, _______, _______, _______,                        _______, KC_4, KC_5, KC_6, _______, _______, 
      _______, _______, _______, _______, _______, _______, _______,      _______, _______, KC_1, KC_2, KC_3, _______, _______, 
      _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, 

      _______, _______,                                                   _______, _______, 
      _______, _______, _______,                                          _______, _______, _______, 
      _______, _______, _______,                                          _______, KC_0, _______
  ),
};
// clang-format on

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
        case L_NUMS:
            ergodox_right_led_1_on();
            break;
        case L_MEDIA:
            ergodox_right_led_2_on();
            break;
        case L_SYMBOLS:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};


// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t eq_numlayer_arrow_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void dquo_plus_each(tap_dance_state_t *state, void *user_data) { 
    if (state->count == 1) {
        register_code16(KC_DQUO);
    } else {
        unregister_code16(KC_DQUO);
    }
}

void dquo_plus_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_DQUO);
    } else if (state->count == 2){
        tap_code(KC_PPLS);
    } else if (state->count == 3){ 
        SEND_STRING("0p");
    }
}

// void dquo_plus_reset()

// Functions that cntrol what our tap dance key does
void eq_numlayer_arrow_finished(tap_dance_state_t *state, void *user_data) {
    eq_numlayer_arrow_tap_state.state = cur_dance(state);
    switch (eq_numlayer_arrow_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_EQL);
            break;
        case TD_SINGLE_HOLD:
            layer_on(L_NUMS);
            break;
        case TD_DOUBLE_TAP:
            SEND_STRING("=>");
            break;
        default:
            break;
    }
}

void eq_numlayer_arrow_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (eq_numlayer_arrow_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(L_NUMS);
    }
    eq_numlayer_arrow_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for quot, twice for quot then +, three times for quot then + then y
    [TD_QUOT_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(dquo_plus_each, dquo_plus_finished, NULL),
    [TD_EQ_NUMLAYER_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, eq_numlayer_arrow_finished, eq_numlayer_arrow_reset),
};
