#include QMK_KEYBOARD_H
#define BASE 0
#define FN1 1
#define FN2 2
#define MACROLAYER 3

enum my_keycodes {
    NAVYSEAL = SAFE_RANGE,
    TOMMY
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* _LAYER0: Base Layer
     * ,----------------------------------------------------------------.
     * |Esc |  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp|Del |
     * |----------------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |L(2)|
     * |----------------------------------------------------------------|
     * |CAPS(1)|  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
     * |----------------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
     * |----------------------------------------------------------------|
     * |Ctrl|Win |Alt |        Space          | Alt|  FN|  |Lef|Dow|Rig |
     * `----------------------------------------------------------------'
     */
    [BASE] = LAYOUT_65_ansi_blocker( /* Base */
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL,\
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLASH, MO(FN2),\
        LT(FN1, KC_CAPS), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,\
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,\
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(FN1), KC_LEFT, KC_DOWN, KC_RIGHT),
    /* FN1: FN 1
     * ,----------------------------------------------------------------.
     * |    | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|      |PRSC|
     * |----------------------------------------------------------------|
     * |     |   |   |   |   |   |   |   |   |   |   |Vo-|Vo+| Mute|    |
     * |----------------------------------------------------------------|
     * |       |   |   |   |   |   |   |   |   |   |   |   |       | Hom|
     * |----------------------------------------------------------------|
     * |        |   |   |   |   |   |   |   |   |Prv|Ply|NxtTrk|Pg+| End|
     * |----------------------------------------------------------------|
     * |    |    |    |                       |    |    |  |Hom|Pg-| End|
     * `----------------------------------------------------------------'
     */
    [FN1] = LAYOUT_65_ansi_blocker( /* FN 1 */
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_PSCR,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_PGUP, KC_END,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_END),
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
        KC_SLEP, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_TRNS, KC_INS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, RGB_SPD, RGB_SPI, RGB_RMOD, RGB_MOD, RGB_VAD, RGB_VAI, RESET, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, RGB_TOG, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, OSL(MACROLAYER), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [MACROLAYER] = LAYOUT_65_ansi_blocker( /* Macro Layer */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, NAVYSEAL, TOMMY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,\
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

void matrix_init_user(void) {
  //user initialization
}

void matrix_scan_user(void) {
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAVYSEAL:
            if (record->event.pressed) {
                SEND_STRING("What the fuck did you just fucking say about me, you little bitch? I'll have you know I graduated top of my class in the Navy Seals, and I've been involved in numerous secret raids on Al-Quaeda, and I have over 300 confirmed kills. I am trained in gorilla warfare and I'm the top sniper in the entire US armed forces. You are nothing to me but just another target. I will wipe you the fuck out with precision the likes of which has never been seen before on this Earth, mark my fucking words. You think you can get away with saying that shit to me over the Internet? Think again, fucker. As we speak I am contacting my secret network of spies across the USA and your IP is being traced right now so you better prepare for the storm, maggot. The storm that wipes out the pathetic little thing you call your life. You're fucking dead, kid. I can be anywhere, anytime, and I can kill you in over seven hundred ways, and that's just with my bare hands. Not only am I extensively trained in unarmed combat, but I have access to the entire arsenal of the United States Marine Corps and I will use it to its full extent to wipe your miserable ass off the face of the continent, you little shit. If only you could have known what unholy retribution your little \"clever\" comment was about to bring down upon you, maybe you would have held your fucking tongue. But you couldn't, you didn't, and now you're paying the price, you goddamn idiot. I will shit fury all over you and you will drown in it. You're fucking dead, kiddo.");
            }
            break;
        case TOMMY:
            if (record->event.pressed) {
                SEND_STRING("Tommy Myers");
            }
            break;
    }
    return true;
}
