#include QMK_KEYBOARD_H
/*----------------------*/
/*------- ENUMS --------*/
/*----------------------*/
enum unicode_names
{
    B,
};

enum tap_dance_names
{
    TD_SWITCH_LAYERS
};

/*----------------------*/
/*----- FUNCTIONS ------*/
/*----------------------*/

void td_toggle_layers(qk_tap_dance_state_t *state, void *user_data)
{
    switch (state->count)
    {
    case 2:
        backlight_toggle();
    default:
        break;
    }
}

/*----------------------*/
/*---- DEFINITIONS -----*/
/*----------------------*/
const uint32_t PROGMEM unicode_map[] = {
    [B] = 0x1F171,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SWITCH_LAYERS] = ACTION_TAP_DANCE_FN(td_toggle_layers),
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
        KC_LSFT, XXXXXXX, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, XXXXXXX,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_LEFT, TT(1), XXXXXXX, KC_RIGHT, KC_RCTL),

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
