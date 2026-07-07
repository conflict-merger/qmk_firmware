#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                                      │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

enum my_layers {
    _BASE,
    _SYMBLS,
    _NAV,
    _NUM,
    _FUN,
    _GMG
};

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                             │
// └───────────────────────────────────────────────────────────┘

enum custom_keycodes {
    DEFAULT = SAFE_RANGE,
    MEC_PSS,
    QMK_CMP, // Send String: QMK Compile
    PIPE_ARW,
    R_ARRW,
    EQL_ARW
};


// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   t a p  d a n c e s                          │
// └───────────────────────────────────────────────────────────┘

enum {
    CT_Q,
    CT_W,
    CT_E,
    CT_R,
    CT_T,
    CT_EQL,
    CT_GRV,
    CT_ESC,
};

// ┌───────────────────────────────────────────────────────────┐
// | d e f i n e   m a c r o n a m e s                         │
// └───────────────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐
#define MT_A    LGUI_T(KC_A)
#define MT_Z    LGUI_T(KC_Z)
#define MT_S    LALT_T(KC_S)
#define MT_F    LSFT_T(KC_F)
#define MT_D    LCTL_T(KC_D)

// RIGHT HAND HOME ROW MODS ├──────────────────────────────────┐
#define MT_QT   LGUI_T(KC_QUOT)
#define MT_SL   LGUI_T(KC_SLSH)
#define MT_L    LALT_T(KC_L)
#define MT_J    LSFT_T(KC_J)
#define MT_K    LCTL_T(KC_K)

// TAP DANCE ├─────────────────────────────────────────────────┐
#define TD_Q    TD(CT_Q)
#define TD_W    TD(CT_W)
#define TD_E    TD(CT_E)
#define TD_R    TD(CT_R)
#define TD_T    TD(CT_T)
#define TD_EQL  TD(CT_EQL)
#define TD_GRV  TD(CT_GRV)
#define TD_ESC  TD(CT_ESC)

// DEFAULT LAYERS ├────────────────────────────────────────────┐
#define ALP_A     DF(_BASE)
#define ALP_B     DF(_MIXED)

// OTHERS ├────────────────────────────────────────────────────┐
#define MT_SYM   LT(_SYMBLS,KC_BSPC)
#define MT_NAV   LT(_NAV,KC_SPC)
#define MT_FUN   LT(_FUN,KC_TAB)
#define MT_ESC   LGUI_T(KC_ESC)

#define MO_NUM   MO(_NUM)
#define MT_NUM   LT(_NUM, KC_ESC)
#define OSM_LSFT OSM(MOD_LSFT)
#define CTLSFT   OSM(MOD_LSFT | MOD_LCTL)
#define OSM_MEH  OSM(MOD_MEH)
//#define GSTL     OSM(MOD_LGUI | MOD_LCTL)
// #define GUI_CTL  OSM(KC_LGUI | KC_LCTL)

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_split_3x5_3(
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
                  '*', '*', '*',  '*', 'R', 'R'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

    ┌─────────┬─────────┬─────────┬─────────┬─────────┐                    ┌─────────┬─────────┬─────────┬─────────┬─────────┐
    │    Q    │    W    │    E    │    R    │    T    │  ╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮╭╮│    Y    │    U    │    I    │    O    │    P    │
    ┼─────────┼─────────┼─────────┼─────────┼─────────┤ │╰╯╰╯╰╯╰╯╰╯╰╯╰╯╰╯│ ├─────────┼─────────┼─────────┼─────────┼─────────┼
    │    A    │    S    │    D    │    F    │    G    ├─╯                ╰─┤    H    │    J    │    K    │    L    │    "    │
    ┼─────────┼─────────┼─────────┼─────────┼─────────┤                    ├─────────┼─────────┼─────────┼─────────┼─────────┼
    │    Z    │    X    │    C    │    V    │    B    │                    │    N    │    M    │    ,    │    .    │    /    │
    ┴─────────┴─────────┼─────────┼─────────┼─────────┼                    ┼─────────┼─────────┼─────────┼─────────┴─────────┴
                        │  TAB    │   NUM   │   NAV   │                    │  BSPACE │   SFT   │   ENT   │
                        └─────────┴─────────┴─────────┘                    └─────────┴─────────┴─────────┘
   */

   [_BASE] = LAYOUT_split_3x5_3(
        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,       KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
        KC_A,     MT_S,     MT_D,     MT_F,     KC_G,       KC_H,     MT_J,     MT_K,     MT_L,     KC_QUOT,
        MT_Z,     KC_X,     KC_C,     KC_V,     KC_B,       KC_N,     KC_M,     KC_COMM,  KC_DOT,   MT_SL,
                            MT_FUN,   MT_NUM,   MT_NAV,     MT_SYM,   OSM_LSFT, KC_ENT
 ),

   [_SYMBLS] = LAYOUT_split_3x5_3(
        KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,    KC_QUES,  KC_CIRC,  TD_EQL,   KC_AMPR,  KC_PIPE,
        KC_GRV,   KC_GT,    KC_ASTR,  KC_COLN,  KC_PIPE,    KC_MINS,  KC_LPRN,  KC_LBRC,  KC_LCBR,  R_ARRW,
        KC_TILD,  KC_LT,    TD_GRV,   KC_SCLN,  KC_BSLS,    KC_UNDS,  KC_RPRN,  KC_RBRC,  KC_RCBR,  PIPE_ARW,
                            QK_LEAD,  EQL_ARW,  KC_SPC,     KC_BSPC,  KC_NO,    KC_TRNS
 ),

   [_NAV] = LAYOUT_split_3x5_3(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_MPLY,  KC_VOLD,  KC_VOLU,  KC_MNXT,  KC_NO,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_NO,
        KC_NO,    OSM_MEH,  KC_NO,    CTLSFT,   KC_NO,      KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_INS,
                            KC_NO,    KC_NO,    KC_NO,      QK_LEAD,  KC_NO,    KC_DEL
 ),

   [_NUM] = LAYOUT_split_3x5_3(
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_COLN,  KC_7,     KC_8,     KC_9,     KC_ASTR,
        KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_MINS,  KC_4,     KC_5,     KC_6,     KC_PLUS,
        KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      KC_UNDS,  KC_1,     KC_2,     KC_3,     KC_SLSH,
                            KC_NO,    KC_NO,    KC_NO,      KC_BSPC,  KC_0,     KC_DOT
 ),
 
   [_FUN] = LAYOUT_split_3x5_3(
      MEC_PSS,    DM_PLY1,  DM_PLY2,  KC_NO,    KC_NO,      KC_PSCR,  KC_F7,    KC_F8,    KC_F9,    KC_F12,
      QMK_CMP,    KC_LALT,  KC_LCTL,  KC_LSFT,  KC_NO,      KC_NO,    KC_F4,    KC_F5,    KC_F6,    KC_F11,
      QK_BOOT,    DM_REC1,  DM_REC2,  KC_NO,    KC_NO,      KC_NO,    KC_F1,    KC_F2,    KC_F3,    KC_F10,
                            KC_NO,    KC_NO,    DM_RSTP,    DM_PLY1,  DM_REC1,  DM_RSTP
 ),

   [_GMG] = LAYOUT_split_3x5_3(
      KC_T,     KC_Q,     KC_W,     KC_E,     KC_R,         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,
      KC_G,     KC_A,     KC_S,     KC_D,     KC_F,         KC_H,     KC_J,     KC_K,     KC_L,     TG(_GMG),
      KC_B,     KC_Z,     KC_X,     KC_C,     KC_V,         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
                          KC_LCTL,  KC_LSFT,  KC_SPC,       KC_TAB,   KC_ESC,   KC_ENT
 )

};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C O M B O S                                                                                                                                |
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

const uint16_t PROGMEM eql_combo[] = {MT_J, KC_I, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM min_combo[] = {KC_H, MT_J, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {MT_J, MT_K, COMBO_END};

combo_t key_combos[] = {
    COMBO(eql_combo, KC_EQL),
    COMBO(min_combo, KC_MINS),
    COMBO(unds_combo, KC_UNDS),
    COMBO(esc_combo, KC_ESC),
    COMBO(lprn_combo, KC_LPRN),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                                                │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

bool process_record_user(uint16_t keycode, keyrecord_t *record){

    switch(keycode){
        case MEC_PSS:
            if(record->event.pressed) {
                SEND_STRING_DELAY("@D@taH1st0r1an", 20);
            }
            return false;
        case QMK_CMP:
            if(record->event.pressed) {
                SEND_STRING_DELAY("qmk compile -kb crkbd/rev1 -km conflict_merger", 20);
            }
            return false;
        case PIPE_ARW:
            if (record->event.pressed){
                SEND_STRING("|>");
            }
            return false;
        case R_ARRW:
            if (record->event.pressed){
                SEND_STRING("->");
            }
            return false;
        case EQL_ARW:
            if (record->event.pressed){
                SEND_STRING("=>");
            }
            return false;
    }
    return true;

};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        // SEND_STRING("QMK is awesome.");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_Q, KC_M, MT_K)) {
        SEND_STRING_DELAY("qmk compile -kb crkbd/rev1 -km conflict_merger", 20);
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // tap_code16(LGUI(KC_S));
    }
}

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ C A P S W O R D                                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

bool caps_word_press_user(uint16_t keycode) {
    switch(keycode){
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true; 
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_UNDS:
        case KC_DEL:
            return true;

        default:
            return false;
    }
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ T A P D A N C E                                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

tap_dance_action_t tap_dance_actions[] = {
    [CT_EQL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    // [CT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    // [CT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_ENT),
};


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ O V E R R I D E S                                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘

// Ctrl + Play: Next Track
const key_override_t next_track_override = ko_make_with_layers_negmods_and_options( MOD_MASK_CTRL, KC_MPLY, KC_MNXT, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);

// Ctrl + Sft + Play: Previous track
const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CS, KC_MPLY,KC_MPRV, ~0, MOD_MASK_ALT, ko_option_no_reregister_trigger);

const key_override_t capslock_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, KC_CAPS);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
    &next_track_override,
    &prev_track_override,
	&capslock_key_override
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_Z:
            return TAPPING_TERM + 1250;
        case MT_SL:
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}