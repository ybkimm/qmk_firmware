#include QMK_KEYBOARD_H

#include "print.h"
#include "keymap_steno.h"

enum planck_layers {
  _BASE,
  _STENO,
  _STENO_SPC,
  _SPC,
  _LOWER,
  _RAISE,
  _LAISE
};

#define SPC MO(_SPC)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define LAISE MO(_LAISE)
#define STENO_SPC MO(_STENO_SPC)

enum planck_keycodes {
    KC_ATAB = SAFE_RANGE,   // Actually, CMD TAB.
    KC_STST,                // Steno Start
    KC_STEN                 // Steno End
};

#define KC_OPTL LOPT(KC_LEFT)  // ⌥→
#define KC_CMDL LCMD(KC_LEFT)  // ⌘→
#define KC_OPTR LOPT(KC_RIGHT) // ⌥→
#define KC_CMDR LCMD(KC_RIGHT) // ⌘→
#define KC_CMRT LCMD(KC_ENT)   // ⌘↩
#define KC_CMBS LCMD(KC_BSPC)  // ⌘⌫
#define KC_SSPC LSFT(KC_SPC)   // ⇧␣

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Base
     *  -----------------------------------------------------------------------------------------------
     * |   ⎋   |   Q   |   W   |   E   |   R   |   T   |   Y   |   U   |   I   |   O   |   P   |   ⌫   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇥   |   A   |   S   |   D   |   F   |   G   |   H   |   J   |   K   |   L   |   '   |   ↩   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   Z   |   X   |   C   |   V   |   B   |   N   |   M   |   ,   |   .   |   /   |  ⇧ ␣  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⌃   |   ⌥   |   ⌘   |  SPC  | Lower |       ␣       | Raise |   ←   |   ↓   |   ↑   |   →   |
     *  -----------------------------------------------------------------------------------------------
     */
    [_BASE] = LAYOUT_planck_1x2uC(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SSPC,
        KC_LCTL, KC_LALT, KC_LGUI, SPC,     LOWER,   KC_SPC,           RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    /* Steno (opensteno.org)
     *  -----------------------------------------------------------------------------------------------
     * |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |   #   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  F N  |   S   |   T   |   P   |   H   |   *   |   *   |   F   |   P   |   L   |   T   |   D   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |   S   |   K   |   W   |   R   |   *   |   *   |   R   |   B   |   G   |   S   |   Z   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  END  |  N/A  |  N/A  |   A   |   O   |   STENO SPC   |   E   |   U   |  PWR  | RES 1 | RES 2 |
     *  -----------------------------------------------------------------------------------------------
     */
    [_STENO] = LAYOUT_planck_1x2uC(
        STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
        STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
        KC_STEN, XXXXXXX, XXXXXXX, STN_A,   STN_O,   STENO_SPC,        STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
    ),
    /* Steno Special
     *  -----------------------------------------------------------------------------------------------
     * |       |       |       |       |       |       |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       |       |       |       |       |       |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |               |       |       |       |       |       |
     *  -----------------------------------------------------------------------------------------------
     */
    [_STENO_SPC] = LAYOUT_planck_1x2uC(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    /*  Special / Numpad
     *  -----------------------------------------------------------------------------------------------
     * |   `   |       |  ⌘ W  |  ⌘ E  |  ⌘ R  |  ⌘ T  |  N/A  |   7   |   8   |   9   |  N/A  |   ⌫   |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  ⌘ ⇥  |  ⌘ A  |  ⌘ S  |  ⌘ D  |  ⌘ F  |  ⌘ G  |  N/A  |   4   |   5   |   5   |  N/A  |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |  ⌘ Z  |  ⌘ X  |  ⌘ C  |  ⌘ V  |  ⌘ B  |  N/A  |   1   |   2   |   3   |   .   |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |  N/A  |       ␣       |   0   |  ⌥ ←  |   ⇟   |   ⇞   |  ⌥ →  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_SPC] = LAYOUT_planck_1x2uC(
        KC_GRV,  _______, G(KC_W), G(KC_E), G(KC_R), G(KC_T), XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, KC_BSPC,
        KC_ATAB, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G), XXXXXXX, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, KC_ENT,
        KC_LSFT, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______,
        _______, _______, _______, _______, XXXXXXX, KC_SPC,           KC_P0,   KC_OPTL, KC_PGDN, KC_PGUP, KC_OPTR
    ),
    /*  Lower
     *  -----------------------------------------------------------------------------------------------
     * |   ~   |   !   |   @   |   #   |   $   |   %   |   ^   |   &   |   *   |   (   |   )   |  ⌘ ⌫  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |   -   |   =   |   +   |  N/A  |  N/A  |  N/A  |  N/A  |   {   |   }   |   :   |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   _   |   \   |   |   |  N/A  |  N/A  |  N/A  |  N/A  |   [   |   ]   |   ;   |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |       |       |       |       |       |       ␣       | Raise |  ⌘ ←  |   ⇟   |   ⇞   |  ⌘ →  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_LOWER] = LAYOUT_planck_1x2uC(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CMBS,
        XXXXXXX, KC_MINS, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_COLN, KC_CMRT,
        KC_LSFT, KC_UNDS, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SCLN, _______,
        _______, _______, _______, _______, XXXXXXX, KC_SPC,           LAISE,   KC_CMDL, KC_PGDN, KC_PGUP, KC_CMDR
    ),
    /*  Raise
     *  -----------------------------------------------------------------------------------------------
     * |   `   |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |   0   |  ⌘ ⌫  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |   -   |   =   |   +   |  N/A  |  N/A  |  N/A  |  N/A  |   {   |   }   |   :   |  ⌘ ↩  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |   ⇧   |   _   |   \   |   |   |  N/A  |  N/A  |  N/A  |  N/A  |   [   |   ]   |   ;   |       |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  MRD  | VOL ↓ | VOL ↑ |  MFD  | Lower |   MusicPlay   |       |  ⌘ ←  |   ⇟   |   ⇞   |  ⌘ →  |
     *  -----------------------------------------------------------------------------------------------
     *  MRD/MFD: Music Rewind/Forward (MacOS)
     */
    [_RAISE] = LAYOUT_planck_1x2uC(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CMBS,
        XXXXXXX, KC_MINS, KC_EQL,  KC_PLUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_COLN, KC_CMRT,
        KC_LSFT, KC_UNDS, KC_BSLS, KC_PIPE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SCLN, _______,
        KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, LAISE,   KC_MPLY,          _______, KC_CMDL, KC_PGDN, KC_PGUP, KC_CMDR
    ),
    /*  Lower + Raise
     *  -----------------------------------------------------------------------------------------------
     * |  ⌃ 0  |  ⌃ 1  |  ⌃ 2  |  ⌃ 3  |  ⌃ 4  |  ⌃ 5  |  ⌃ 6  |  ⌃ 7  |  ⌃ 8  |  ⌃ 9  |  N/A  |  N/A  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  F 0  |  F 1  |  F 2  |  F 3  |  F 4  |  F 5  |  F 6  |  F 7  |  F 8  |  F 9  |  F10  |  F11  |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |  ⌃ `  |  N/A  |  ⌘⇧3  |  ⌘⇧4  |  N/A  |  N/A  |  N/A  |  N/A  | STENO |
     * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
     * |  N/A  |  N/A  |  N/A  |  N/A  |       |      N/A      |       |  N/A  |  N/A  |  N/A  |  N/A  |
     *  -----------------------------------------------------------------------------------------------
     */
    [_LAISE] = LAYOUT_planck_1x2uC(
        G(KC_0), G(KC_1), G(KC_2), G(KC_3),   G(KC_4), G(KC_5),    G(KC_6),   G(KC_7), G(KC_8), G(KC_9), XXXXXXX, XXXXXXX,
        KC_F1,   KC_F2,   KC_F3,   KC_F4,     KC_F5,   KC_F6,      KC_F7,     KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, C(KC_GRV), XXXXXXX, G(KC_HASH), G(KC_DLR), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_STST,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
};

#ifdef AUDIO_ENABLE
    float planck_song[][2]      = SONG(PLANCK_SOUND);
    float plover_song[][2]      = SONG(PLOVER_SOUND);
    float plover_gb_song[][2]   = SONG(PLOVER_GOODBYE_SOUND);
#endif

void keyboard_post_init_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(planck_song);
    #endif
    #ifdef RGBLIGHT_ENABLE
        rgblight_disable();
    #endif
    #ifdef STENO_ENABLE
        steno_set_mode(STENO_MODE_GEMINI);
    #endif
}

bool atab_enabled = false;

void enable_atab(void) {
    register_code(KC_G);
    atab_enabled = true;
}

void disable_atab(void) {
    unregister_code(KC_G);
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
        case KC_STST:
            #ifdef STENO_ENABLE
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(plover_song);
                #endif
                layer_on(_STENO);
            #endif
            return false;
            break;
        case KC_STEN:
            #ifdef STENO_ENABLE
                #ifdef AUDIO_ENABLE
                    stop_all_notes();
                    PLAY_SONG(plover_gb_song);
                #endif
                layer_off(_STENO);
            #endif
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
