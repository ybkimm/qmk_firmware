#include QMK_KEYBOARD_H

#include "print.h"

enum planck_layers {
  _BASE,
  _SPC,
  _LOWER,
  _RAISE,
  _LAISE
};

#define SPC MO(_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LAISE MO(_LAISE)

enum planck_keycodes {
    KC_ATAB = SAFE_RANGE // Actually, CMD TAB.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Base
     *  -----------------------------------------------------------------------------------------------
     * |   ⎋   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   ⌫   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇥   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   '   |   ↩   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |  F16  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⌃   |   ⌥   |   ⌘   |  SPC  | Lower |       ␣       | Raise |   ←   |   ↓   |   ↑   |   →   |
     *  -----------------------------------------------------------------------------------------------
     */
    [_BASE] = LAYOUT_planck_1x2uC(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_F16,
        KC_LCTL, KC_LALT, KC_LGUI, SPC,     LOWER,   KC_SPC,           RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /*  Special / Numpad
     *  -----------------------------------------------------------------------------------------------
     * |   `   |  N/A  |  ⌘ W  |  ⌘ E  |  ⌘ R  |  ⌘ T  |  N/A  |   7   |   8   |   9   |  N/A  |  ⌘ ⌫  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  ⌘ ⇥  |  ⌘ A  |  ⌘ S  |  ⌘ D  |  ⌘ F  |  ⌘ G  |  N/A  |   4   |   5   |   5   |   0   |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |  ⌘ Z  |  ⌘ X  |  ⌘ C  |  ⌘ V  |  ⌘ B  |  N/A  |   1   |   2   |   3   |   0   |  F16  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |       |  N/A  |       ␣       |   0   |  ⌘ ←  |   ⇟   |   ⇞   |  ⌘ →  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_SPC] = LAYOUT_planck_1x2uC(
        KC_GRV, _______,     LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T), XXXXXXX, KC_7,    KC_8,          KC_9,    XXXXXXX, LGUI(KC_BSPC),
        KC_ATAB, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G), XXXXXXX, KC_4,    KC_5,          KC_6,    KC_0,    LGUI(KC_ENT),
        KC_LSFT, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LGUI(KC_B), XXXXXXX, KC_1,    KC_2,          KC_3,    KC_0,    _______,
        _______, _______,    _______,    _______,    XXXXXXX,    KC_SPC,              KC_0,    LGUI(KC_LEFT), KC_PGDN, KC_PGUP, LGUI(KC_RGHT)
    ),
    /*  Lower
     *  -----------------------------------------------------------------------------------------------
     * |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  ⌘ ⌫  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |   -   |   =   |   +   |  N/A  |  N/A  |  N/A  |  N/A  |   {   |   }   |   :   |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   _   |   \   |   |   |  N/A  |  N/A  |  N/A  |  N/A  |   [   |   ]   |   ;   |  F16  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |       |       |       ␣       | Raise |  ⌘ ←  |   ⇟   |   ⇞   |  ⌘ →  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_LOWER] = LAYOUT_planck_1x2uC(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,       KC_LPRN, KC_RPRN, LGUI(KC_BSPC),
        XXXXXXX, KC_MINS, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR,       KC_RCBR, KC_COLN, LGUI(KC_ENT),
        KC_LSFT, KC_UNDS, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,       KC_RBRC, KC_SCLN, _______,
        _______, _______, _______, _______, XXXXXXX, KC_SPC,           LAISE,   LGUI(KC_LEFT), KC_PGDN, KC_PGUP, LGUI(KC_RGHT)
    ),
    /*  Raise
     *  -----------------------------------------------------------------------------------------------
     * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  ⌘ ⌫  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |   -   |   =   |   +   |  N/A  |  N/A  |  N/A  |  N/A  |   {   |   }   |   :   |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   _   |   \   |   |   |  N/A  |  N/A  |  N/A  |  N/A  |   [   |   ]   |   ;   |  F16  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  MRD  | VOL ↓ | VOL ↑ |  MFD  | Lower |   MusicPlay   |       |  ⌘ ←  |   ⇟   |   ⇞   |  ⌘ →  |
     *  -----------------------------------------------------------------------------------------------
     *  MRD/MFD: Music Rewind/Forward (MacOS)
     */
    [_RAISE] = LAYOUT_planck_1x2uC(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,          KC_9,    KC_0,    LGUI(KC_BSPC),
        XXXXXXX, KC_MINS, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR,       KC_RCBR, KC_COLN, LGUI(KC_ENT),
        KC_LSFT, KC_UNDS, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC,       KC_RBRC, KC_SCLN, _______,
        KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, LAISE,   KC_MPLY,          _______, LGUI(KC_LEFT), KC_PGDN, KC_PGUP, LGUI(KC_RGHT)
    ),
    /*  Lower + Raise
     *  -----------------------------------------------------------------------------------------------
     * |  ⌃ 0  |  ⌃ 1  |  ⌃ 2  |  ⌃ 3  |  ⌃ 4  |  ⌃ 5  |  ⌃ 6  |  ⌃ 7  |  ⌃ 8  |  ⌃ 9  |  N/A  |  N/A  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  F 0  |  F 1  |  F 2  |  F 3  |  F 4  |  F 5  |  F 6  |  F 7  |  F 8  |  F 9  |  F10  |  F11  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |  ⌃ `  |  N/A  |  ⌘⇧3  |  ⌘⇧4  |  N/A  |  N/A  |  N/A  |  N/A  |  N/A  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |  N/A  |       |      N/A      |       |  N/A  |  N/A  |  N/A  |  N/A  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_LAISE] = LAYOUT_planck_1x2uC(
        LGUI(KC_0), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3),   LGUI(KC_4), LGUI(KC_5),    LGUI(KC_6),   LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______, _______,
        KC_F1,      KC_F2,      KC_F3,      KC_F4,        KC_F5,      KC_F6,         KC_F7,        KC_F8,      KC_F9,      KC_F10,     KC_F11,  KC_F12,
        _______,    _______,    _______,    LCTL(KC_GRV), _______,    LGUI(KC_HASH), LGUI(KC_DLR), _______,    _______,    _______,    _______, _______,
        _______,    _______,    _______,    _______,      _______,    _______,                     _______,    _______,    _______,    _______, _______
    )
};

#ifdef AUDIO_ENABLE
    float planck_song[][2] = SONG(PLANCK_SOUND);
#endif

void keyboard_post_init_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(planck_song);
    #endif
    #ifdef RGBLIGHT_ENABLE
        rgblight_disable();
    #endif
}

bool atab_enabled = false;

void enable_atab(void) {
    register_code(KC_LGUI);
    atab_enabled = true;
}

void disable_atab(void) {
    unregister_code(KC_LGUI);
    atab_enabled = false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ATAB:
            if (record->event.pressed) {
                if (!atab_enabled) {
                    enable_atab();
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
            break;
        default:
            if (atab_enabled) {
                disable_atab();
            }
            break;
    }
    return true;
}
