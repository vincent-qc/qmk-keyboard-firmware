#include QMK_KEYBOARD_H
/*----------------------*/
/*------- ENUMS --------*/
/*----------------------*/

enum unicode_names
{
    AMOGUS,
};

enum tap_dance_names
{
    TD_SWITCH_LAYERS,
};

enum custom_keycodes
{
    MACRO_CLICK = SAFE_RANGE,
    TOGGLE_MC_LAYER = 0xFF,
};

/*----------------------*/
/*----- FUNCTIONS ------*/
/*----------------------*/

void td_toggle_layers(qk_tap_dance_state_t *state, void *user_data)
{
    if (state->count == 1)
    {
        // send_unicode_string("ඞ");
        // reset_tap_dance(state);
    }
    else if (state->count == 2)
    {
        // layer_on(2);
        // reset_tap_dance(state);
    }
}

/*----------------------*/
/*---- DEFINITIONS -----*/
/*----------------------*/

const uint32_t PROGMEM unicode_map[] = {
    [AMOGUS] = 0xe0b69e,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    //[TD_SWITCH_LAYERS] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RCTL, 2),
};

/*----------------------*/
/*------ KEYMAPS -------*/
/*----------------------*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty Base layer
    * ,-----------------------------------------------------------------------------------------.
    * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  | Backspace |
    * |-----------------------------------------------------------------------------------------+
    * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \    |
    * |-----------------------------------------------------------------------------------------+
    * | CAPS    |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter    |
    * |-----------------------------------------------------------------------------------------+
    * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  |   Right Shift   |
    * |-----------------------------------------------------------------------------------------+
    * | Ctrl  |  CMD  |  Alt  |               Space               | Right |  FN  | Left | LYR+  |
    *  `----------------------------------------------------------------------------------------'
    */

    LAYOUT(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, TOGGLE_MC_LAYER, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, TT(2), XXXXXXX, KC_RIGHT, KC_RCTL),

    /* --------------------------- ALL SPECIAL LAYERS GO UNDER HERE --------------------------- */

    /* Minecraft CPS Layer
    *
    * MS = Mouse Button 1 (aka left click)
    * 
    * ,-----------------------------------------------------------------------------------------.
    * |     |     |     |     |     |     |     |     |     |     |     |     |     |   Delete  |
    * |-----------------------------------------------------------------------------------------+
    * |        |  MS  |     |     |     |     |     |     |     |     |     |     |     |       |
    * |-----------------------------------------------------------------------------------------+
    * |   MS    |     |     |     |  MS  |     |     |     |     |     |     |     |            |
    * |-----------------------------------------------------------------------------------------+
    * |             |     |     |     |     |     |     |     |     |     |     |               |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                   |       |      |      |       |
    *  `----------------------------------------------------------------------------------------'
    */

    LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, MACRO_CLICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        MACRO_CLICK, KC_TRNS, KC_TRNS, KC_TRNS, MACRO_CLICK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______, KC_TRNS, KC_TRNS, TO(0)),

    /* FN Layer
    * ,-----------------------------------------------------------------------------------------.
    * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 |  F10 |  F11 |  F12 | Delete |
    * |-----------------------------------------------------------------------------------------+
    * |        | TOG | OFF |     |     |     |     |     |     |     |     | SLP | WKE |  PRSCN |
    * |-----------------------------------------------------------------------------------------+
    * |         |     |     |     |     |     |     |     |     |     |     |     |    RESET    |
    * |-----------------------------------------------------------------------------------------+
    * |           |     |     |     |     | VOL- | VOL+ | PLY | PRV | NXT | MTE |               |
    * |-----------------------------------------------------------------------------------------+
    * |       |       |       |                                   |  Up   |  FN  | Down | LYR+  |
    *  `----------------------------------------------------------------------------------------'
    */

    LAYOUT(
        KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, KC_DEL,
        RGB_MODE_FORWARD, RGB_TOG, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, KC_SLEP, KC_WAKE, KC_PSCREEN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,
        _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_UP, _______, _______, KC_DOWN, TO(0)),
};

/*----------------------*/
/*------- MACROS -------*/
/*----------------------*/

uint16_t counter = 0;
uint16_t timer = 0;
bool triggered = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    // FAST CLICK FOR MC PVP
    case MACRO_CLICK:
        if (record->event.pressed)
        {
            // Pressed
            triggered = true;
        }
        else
        {
            triggered = false;
            // Released
        }
        break;

    // TOGGLES MACRO LAYERS
    case TOGGLE_MC_LAYER:
        if (record->event.pressed)
        {

            // Make timer to ensure pressed within 350ms
            timer = timer_read();
            if (counter > 1)
            {
                layer_off(2);
                layer_on(1);
                counter = 0;
            }
            else
            {
                counter++;
            }
        }
        else
        {
            // Released
        }
    }
    return true;
};

uint16_t trigger_timer = 0;

// Reset counter if not pressed fast enough
void matrix_scan_user(void)
{
    if (timer_elapsed(timer) > 350)
    {
        counter = 0;
    }

    if (triggered && timer_elapsed(trigger_timer) > 250)
    {
        trigger_timer = timer_read();
        tap_code_delay(KC_BTN1, 42);
        tap_code_delay(KC_BTN1, 31);
        tap_code_delay(KC_BTN1, 54);
        tap_code_delay(KC_BTN1, 28);
        tap_code_delay(KC_BTN1, 49);
    }
}