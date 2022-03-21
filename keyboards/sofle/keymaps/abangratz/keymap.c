#include QMK_KEYBOARD_H

#include "features/caps_word.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  |  F10 |  F11 | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | <-   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  /   |   A  |   S  |LT_A/D|LT_L/F| LS/G |-------.    ,-------| RS/H |LT_L/J|   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| Mute  |    | DT Pri|------+------+------+------+------+------|
 * |  [   |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   \  |  ]   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TT L | TT R | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
 *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_F1,  KC_F2,   KC_F3,   KC_F4,     KC_F5,     KC_F6,                KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,      KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_SLSH,  KC_A,   KC_S,LT(_ADJUST,KC_D),LT(_LOWER,KC_F),LSFT_T(KC_G),           RSFT_T(KC_H),LT(_LOWER,KC_J),    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LBRC,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE, DT_PRNT  , KC_N,    KC_M, KC_COMM,  KC_DOT, KC_BSLS,  KC_RBRC,
  TT(_LOWER), TT(_RAISE),LCTL_T(KC_TAB),LGUI_T(KC_SPC),LALT_T(KC_ESC),RALT_T(KC_ENT),RGUI_T(KC_SPC), RCTL_T(KC_CAPS), KC_MINS, KC_EQL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  !   |  @   |  /   |  \   |      |                    |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  [   |  ]   |  (   |  )   |LShift|-------.    ,-------|RShift|   4  |   5  |   6  |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |   .  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | TT 1 |      | LC_t |LG_t  | /LA_t   /       \ RA_t \  |RG_t  | RC_t |  -    |  =   |
 *            |      |      | Tab  |Spc   |/  Esc  /         \Enter \ |Spc   | CAPS |       |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
 _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______,   _______,  _______,
 _______, KC_EXLM,   KC_AT, KC_SLSH, KC_BSLS, _______,                    _______,   KC_7 ,   KC_8 ,   KC_9 ,   _______,  _______,
 _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LSFT,                    KC_RSFT,   KC_4 ,   KC_5 ,   KC_6 ,   _______,  _______,
 _______, _______, _______, _______, _______, _______, _______, _______,  KC_0 ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_DOT ,  _______,
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      |      |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_BSPC,
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, XXXXXXX,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC,
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______,
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------| G_C_J|G_C_AL| G_O  |G_C_AR|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| G_C_K| PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  _______ , _______,  _______ ,  _______ , _______, _______,                     _______, _______, _______, _______, _______, _______,
  RESET  , _______,_______,_______,_______,_______,                     _______, _______, _______, _______, _______, _______,
  _______ , _______,_______, _______,    _______,  _______,                     G(C(KC_J)), G(KC_LEFT), G(KC_O), G(KC_RGHT), _______, _______,
  _______ , _______, _______, _______,    _______,  _______, _______,     _______, G(C(KC_L)), KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
#ifdef RGBLIGHT_ENABLE
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    bool    is_ctrl  = (temp_mod | temp_osm) & MOD_MASK_CTRL;
    bool    is_shift = (temp_mod | temp_osm) & MOD_MASK_SHIFT;

    if (is_shift) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                rgblight_decrease_sat();
            } else {
                rgblight_increase_sat();
            }
        }
    } else if (is_ctrl) {
        if (index == 0) { /* First encoder */
            if (clockwise) {
                rgblight_increase_val();
            } else {
                rgblight_decrease_val();
            }
        } else if (index == 1) { /* Second encoder */
            if (clockwise) {
                rgblight_increase_speed();
            } else {
                rgblight_decrease_speed();
            }
        }
    } else {
#endif
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                g_tapping_term += 5;
            } else {
                g_tapping_term -= 5;
            }
        }
#ifdef RGBLIGHT_ENABLE
    }
#endif
    return true;
}

#endif
