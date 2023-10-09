/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "yamd1.h"

// clang-format off
#define LSHIFT_Z MT(MOD_LSFT, KC_Z)
#define LY3_BSPC LT(3, KC_BSPC)
#define LY1_BSPC LT(1, KC_BSPC)
#define LY2_ENT  LT(2, KC_ENT)
#define CGR      LCTL(LGUI(KC_RIGHT))
#define CGL      LCTL(LGUI(KC_LEFT))
#define CG_LOCK  LCTL(LGUI(KC_L))
#define ALT_SPC  LALT(KC_SPC)

#define HRC_L_CTL LT(0, KC_LCTL)
#define HRC_L_SFT OSM(MOD_LSFT)
#define HRC_L_ALT LT(0, KC_LALT)
#define HRC_L_GUI OSM(MOD_LGUI)
#define HRC_R_CTL LT(0, KC_RCTL)
#define HRC_R_SFT OSM(MOD_LSFT)
#define HRC_R_ALT LT(0, KC_RALT)
#define HRC_R_GUI OSM(MOD_LGUI)
#define HRC_L_CTL_SFT OSM(MOD_LCTL | MOD_LSFT)
#define HRC_R_CTL_SFT OSM(MOD_LCTL | MOD_LSFT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     ,  KC_W     ,  KC_E     ,  KC_R     ,  KC_T     ,                               KC_Y     ,  KC_U     ,  KC_I     ,  KC_O     ,  KC_P     ,
    KC_A     ,  KC_S     ,  KC_D     ,  KC_F     ,  KC_G     ,                               KC_H     ,  KC_J     ,  KC_K     ,  KC_L     ,  KC_SCLN  ,
    LSHIFT_Z ,  KC_X     ,  KC_C     ,  KC_V     ,  KC_B     ,                               KC_N     ,  KC_M     ,  KC_COMM  ,  KC_DOT   ,  KC_SLSH  ,
    KC_LCTL  ,  KC_LGUI  ,  KC_LALT  ,  LY3_BSPC ,  MO(1)    ,  KC_SPC   ,      KC_ENT    ,  MO(2)    ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,  KC_TAB
    ),

  [1] = LAYOUT_universal(
    KC_F1    ,  KC_F2    ,  KC_F3    ,  KC_F4    ,  KC_F5    ,                              KC_F6    ,  KC_F7    ,  KC_F8    ,  KC_F9    ,  KC_F10   ,
    KC_ESC   ,  KC_BTN3  ,  KC_BTN2  ,  KC_BTN1  ,  XXXXXXX  ,                              XXXXXXX  ,  KC_BTN1  ,  KC_BTN2  ,  KC_BTN3  ,  KC_F11   ,
    _______  ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,                              XXXXXXX  ,  KC_BTN4  ,  KC_BTN5  ,  XXXXXXX  ,  KC_F12   ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,      _______  ,  _______  ,  _______  ,  _______  ,  _______  , KC_RIGHT_SHIFT
    ),

  [2] = LAYOUT_universal(
    KC_1     ,  KC_2     ,  KC_3     ,  KC_4     ,  KC_5    ,                               KC_6     ,  KC_7     ,  KC_8     ,  KC_9      ,  KC_0     ,
    S(KC_1)  ,  S(KC_2)  ,  S(KC_3)  ,  S(KC_4)  ,  S(KC_5) ,                               KC_MINUS ,  KC_EQL   ,  S(KC_9)  ,  S(KC_0)   ,  KC_QUOT  ,
    _______  ,  C(KC_X)  ,  C(KC_C)  ,  C(KC_V)  ,  C(KC_Z) ,                               XXXXXXX  ,  KC_GRV   ,  KC_LBRC  ,  KC_RBRC   ,  KC_BSLS  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______ ,  _______  ,       _______  ,  _______  ,  _______  ,  _______  ,  _______   , _______
    ),

  [3] = LAYOUT_universal(
    CG_LOCK  ,  _______  ,  _______  ,  _______  ,  _______  ,                              _______  ,  _______  ,  ALT_SPC  ,  _______  ,  KC_PSCR  ,
    _______  ,  _______  ,  KC_LCTL  ,  KC_LSFT  ,  _______  ,                              KC_LEFT  ,  KC_DOWN  ,  KC_UP    ,  KC_RIGHT ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                              CGL      ,  CGR      ,  _______  ,  _______  ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,      _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______
  ),

  [4] = LAYOUT_universal(
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                              _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                              _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                              _______  ,  _______  ,  _______  ,  _______  ,  _______  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______  ,      _______  ,  _______  ,  _______  ,  _______  ,  _______  ,  _______
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

/**
 * combo
 */
const uint16_t PROGMEM combo_w_e[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_m_comm[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_c_v[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_d_f[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_s_f[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM combo_s_d[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_a_f[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_k_j[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_l_j[] = {KC_L, KC_J, COMBO_END};
const uint16_t PROGMEM combo_l_k[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_scln_j[] = {KC_SCLN, KC_J, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {KC_O, KC_P, COMBO_END};

enum combo_events {
  COMBO_ESC1,
  COMBO_ESC2,
  COMBO_IME_ON,
  COMBO_IME_OFF,
  COMBO_BSPC,

    COMBO_HRC_L_CTL,
    COMBO_HRC_L_SFT,
    COMBO_HRC_L_ALT,
    COMBO_HRC_L_GUI,
    COMBO_HRC_R_CTL,
    COMBO_HRC_R_SFT,
    COMBO_HRC_R_ALT,
    COMBO_HRC_R_GUI,
    COMBO_HRC_L_CTL_SFT,
    COMBO_HRC_R_CTL_SFT,

    COMBO_SAFE_RANGE,
};

combo_t key_combos[] = {
  [COMBO_HRC_L_CTL] = COMBO(combo_d_f, HRC_L_CTL),
  [COMBO_HRC_L_SFT] = COMBO(combo_s_f, HRC_L_SFT),
  [COMBO_HRC_L_ALT] = COMBO(combo_s_d, HRC_L_ALT),
  [COMBO_HRC_L_GUI] = COMBO(combo_a_f, HRC_L_GUI),
  [COMBO_HRC_R_CTL] = COMBO(combo_k_j, HRC_R_CTL),
  [COMBO_HRC_R_SFT] = COMBO(combo_l_j, HRC_R_SFT),
  [COMBO_HRC_R_ALT] = COMBO(combo_l_k, HRC_R_ALT),
  [COMBO_HRC_R_GUI] = COMBO(combo_scln_j, HRC_R_GUI),

  [COMBO_ESC1] = COMBO_ACTION(combo_w_e),
  [COMBO_ESC2] = COMBO_ACTION(combo_i_o),
  [COMBO_IME_ON] = COMBO(combo_m_comm, KC_LNG2),
  [COMBO_IME_OFF] = COMBO_ACTION(combo_c_v),

  [COMBO_BSPC] = COMBO(combo_o_p, KC_BSPC),
};

// clang-format on
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_ESC1:
        case COMBO_ESC2:
            if (pressed) {
                tap_code(KC_LNG2);
                register_code(KC_ESC);
            } else {
                unregister_code(KC_ESC);
            }
        case COMBO_IME_OFF:
            // tap_code(IME_CANCEL as uint8_t);
            tap_code(KC_LNG1);
            break;
        default:
            break;
    }
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
