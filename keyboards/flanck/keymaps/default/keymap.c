// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _GMG,
    _SYMB,
    _NUM,
    _NAV,
    _FUN
};

enum {
    TD_E_PLUS,
    TD_L_RPRN,
    TD_L_RBRC,
    TD_L_RCBR
};

enum custom_keycodes {
    DEFAULT = SAFE_RANGE,
    MEC_PSS,
    QMK_CMP_HELIOS,
    PIPE_ARW,
    ARRW,
    EQL_ARW
};

#define MO_NUM MO(_NUM)
#define MO_FUN MO(_FUN)
#define MO_NAV MO(_NAV)

#define MT_A    LGUI_T(KC_A)
#define MT_S    LALT_T(KC_S)
#define MT_F    LSFT_T(KC_F)
#define MT_D    LCTL_T(KC_D)

#define MT_QUOT LGUI_T(KC_QUOT)
#define MT_L    LALT_T(KC_L)
#define MT_J    LSFT_T(KC_J)
#define MT_K    LCTL_T(KC_K)

#define MY_BSPC LCTL(KC_BSPC)

#define MT_SYM  LT(_SYMB, KC_BSPC)
#define MT_NAV  LT(_NAV, KC_SPC)
#define MT_FUN  LT(_FUN, KC_TAB)


#define OS_LSFT OSM(MOD_LSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)

#define MO_GMG  MO(_GMG)

#define TD_EQL  TD(TD_E_PLUS)
#define TD_LPRN TD(TD_L_RPRN)
#define TD_LBRC TD(TD_L_RBRC)
#define TD_LCBR TD(TD_L_RCBR)

tap_dance_action_t tap_dance_actions[] = {
    [TD_E_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
    [TD_L_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_L_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_L_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR)
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ortho_4x12(
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*', 
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*', 
        '*', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', '*', 
        '*', '*', '*', '*', '*', '*',  '*', '*', '*', '*', '*', '*'
    );


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MY_BSPC,
        KC_ESC,  MT_A,    MT_S,    MT_D,    MT_F,    KC_G,    KC_H,    MT_J,    MT_K,    MT_L,    MT_QUOT, KC_ENT,
        DM_REC1, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_VOLU,
        DM_PLY1, DM_RSTP, KC_NO,   MT_FUN,  MO_NUM,  MT_NAV,  MT_SYM,  OS_LSFT, KC_ENT,  KC_NO,   MO_GMG,  KC_VOLD
    ), 

    [_GMG] = LAYOUT_ortho_4x12(
        KC_TAB,  KC_T,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    QK_LLCK,
        KC_LALT, KC_G,    KC_A,    KC_S,    KC_D,    KC_F,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
      OSL(_NUM), KC_B,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_NO,
        KC_CIRC, KC_QUES, KC_LALT, KC_LCTL, KC_LSFT, KC_SPC,  KC_ESC,  KC_ESC,  KC_ENT,  KC_NO,   QK_LLCK, QK_LLCK
    ),

    [_SYMB] = LAYOUT_ortho_4x12(
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_QUES, KC_CIRC, TD_EQL,  KC_AMPR, ARRW,   KC_PLUS,
        KC_TRNS, KC_GRV,  KC_GT,   KC_ASTR, KC_COLN, KC_PIPE, KC_MINS, TD_LPRN, TD_LBRC, TD_LCBR, KC_NO,   KC_ENT,
        KC_NO,   KC_TILD, KC_LT,   KC_GRV,  KC_SCLN, KC_BSLS, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   EQL_ARW,PIPE_ARW, KC_SPC,  KC_BSPC, KC_LSFT, KC_ENT,  KC_NO,   KC_NO,   KC_NO
    ),
      
    [_NUM] = LAYOUT_ortho_4x12(
        KC_NO,   KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_COLN, KC_7,    KC_8,    KC_9,    KC_ASTR,  KC_NO,
        KC_NO,   KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS,  KC_ENT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_1,    KC_2,    KC_3,    KC_SLSH,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_0,    KC_DOT,  KC_BSLS, KC_NO,    KC_NO
    ),
        
    [_NAV] = LAYOUT_ortho_4x12(
        KC_NO,   OS_LGUI, OS_LALT, OS_LCTL, OS_LSFT, KC_NO,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,  KC_NO,
        KC_TAB,  KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,    KC_NO,
        KC_NO,   KC_NO,   OS_LALT, OS_LCTL, OS_LSFT, KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENT,  KC_ESC,  KC_DEL,  KC_NO,   KC_NO,    KC_NO
    ),

    [_FUN] = LAYOUT_ortho_4x12(
 QMK_CMP_HELIOS, MEC_PSS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6,   KC_NO,   KC_ENT,
        KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO
    )
};


const uint16_t PROGMEM eql_combo[] = {MT_J, KC_I, COMBO_END};
const uint16_t PROGMEM lprn_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM min_combo[] = {KC_H, MT_J, COMBO_END};
const uint16_t PROGMEM unds_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {MT_J, MT_K, COMBO_END};
const uint16_t PROGMEM cw_combo[] = {KC_G, KC_H, COMBO_END};


combo_t key_combos[] = {
    COMBO(eql_combo, KC_EQL),
    COMBO(min_combo, KC_MINS),
    COMBO(unds_combo, KC_UNDS),
    COMBO(esc_combo, KC_ESC),
    COMBO(lprn_combo, KC_LPRN),
    COMBO(cw_combo, CW_TOGG)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){

    switch(keycode){
        case MEC_PSS:
            if(record->event.pressed) {
                SEND_STRING_DELAY("@D@taH1st0r1an", 25);
            }
            return false;
        case QMK_CMP_HELIOS:
            if (record->event.pressed) {
                SEND_STRING_DELAY("qmk compile -kb flanck -km default -e CONVERT_TO=helios", 20);
            }
            return false;
        case PIPE_ARW:
            if (record->event.pressed){
                SEND_STRING("|>");
            }
            return false;
        case ARRW:
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


const key_override_t capslock_key_override = ko_make_basic(MOD_MASK_CS, KC_ESC, KC_CAPS);
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

const key_override_t *key_overrides[] = {
	&capslock_key_override,
	&delete_key_override
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
}
