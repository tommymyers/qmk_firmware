#include QMK_KEYBOARD_H
#define BASE 0
#define FN1 1
#define FN2 2
#define MACROLAYER 3

bool bVorM4 = true;

enum my_keycodes {
    TAP_MACRO = SAFE_RANGE,
    TOGGLE_V,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _LAYER0: Base Layer
     * ,----------------------------------------------------------------.
     * |Esc |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp|Del |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
     * |----------------------------------------------------------------|
     * |CAPS(1)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|L(2)|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          | Alt|  FN|  |Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [BASE] = LAYOUT_65_ansi_blocker( /* Base */
        KC_GESC,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,    KC_MINS,     KC_EQL,   KC_BSPC,     KC_DEL,\
        KC_TAB,        KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,    KC_LBRC,     KC_RBRC,  KC_BSLASH,  KC_PGUP,\
        KC_CAPS,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN, KC_QUOT,     KC_ENT,   KC_PGDN,\
        KC_LSFT,       KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH, KC_RSFT,     KC_UP,    MO(FN2),\
        KC_LCTL,       KC_LGUI,    KC_LALT,    KC_SPC,     KC_RALT,    MO(FN1),    KC_LEFT,    KC_DOWN,    KC_RIGHT),
    /* FN1: FN 1
     * ,----------------------------------------------------------------.
     * |    | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|      |PRSC|
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |Vo-|Vo+| Mute| Hom|
     * |----------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |   |       | End|
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |Prv|Ply|NxtTrk|Pg+|    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |Hom|Pg-| End|
     * `----------------------------------------------------------------'
     */
    [FN1] = LAYOUT_65_ansi_blocker( /* FN 1 */
        _______,       KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,     KC_F10,     KC_F11,     KC_F12,    _______,    KC_PSCR,\
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_VOLD,    KC_VOLU,    KC_MUTE,    KC_HOME,\
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     KC_END,\
        _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_PGUP,    _______,\
        _______,     _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_END),
    /* FN2: FN 2
     * ,----------------------------------------------------------------.
     * |Slep|F13|F14|F15|F16|F17|F18|F19|F20|F21|F22|F23|F24|      |Ins |
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |Sp-|Sp+|Md-|Md+|Br-|Br+|Reset|    |
     * |----------------------------------------------------------------|
     * |       |   |   |   |   |   |   |Tog|Hu-|Hu+|Sa-|Sa+|       |    |
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |Mcr|   |   |   |      |   |    |
     * |----------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |   |   |    |
     * `----------------------------------------------------------------'
     */
    [FN2] = LAYOUT_65_ansi_blocker( /* FN 2 */
        KC_SLEP,     KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,          KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,    _______,     KC_INS,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,         RGB_SPD,    RGB_SPI,   RGB_RMOD,    RGB_MOD,    RGB_VAD,    RGB_VAI,      RESET,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,         RGB_TOG,    RGB_HUD,    RGB_HUI,    RGB_SAD,    RGB_SAI,      DEBUG,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______, OSL(MACROLAYER),    _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,         _______,    _______),
    [MACROLAYER] = LAYOUT_65_ansi_blocker( /* Macro Layer */
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,   TOGGLE_V,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,\
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______),
};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

uint16_t timer;
bool keyInterrupted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (read_source_layers_cache(record->event.key) == FN1) {
            keyInterrupted = true;
        }
    }
    //uprintf("%d", read_source_layers_cache(record->event.key));
    switch (keycode) {
        case TOGGLE_V:
            if (record->event.pressed) {
                bVorM4 = !bVorM4;
                //print("toggling v or m4");
                //uprintf("V key now acts as %s", bVorM4 ? "V" : "Mouse 4");
            }
            return true;
        case KC_V:
            if (bVorM4) {
                return true;
            }
            if (record->event.pressed) { 
                register_code(KC_BTN4);
            } else {
                unregister_code(KC_BTN4);
            }
            return false;
        case KC_CAPS:
            if (record->event.pressed) {
                layer_on(FN1);
                timer = timer_read();
            } else {
                layer_off(FN1);
                if(timer_elapsed(timer) < 200 && !keyInterrupted) {
                    tap_code(keycode);
                }
                keyInterrupted = false;
            }
            return false;
        case TAP_MACRO:
            if (record->event.pressed) {
                layer_on(FN2);
                timer = timer_read();
            } else {
                layer_off(FN2);
                if(timer_elapsed(timer) < 200) {
                    //tap_code(OSL(MACROLAYER));
                }
            }
            return false;
    }
    return true;
}
