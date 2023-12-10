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

enum custom_keycodes {
    MY_ARW = KEYBALL_SAFE_RANGE,
    MY_DARW,
};

#define LSHIFT_Z MT(MOD_LSFT, KC_Z)
#define LY3_SPC  LT(3, KC_SPC)
#define CGR      LCTL(LGUI(KC_RIGHT))
#define CGL      LCTL(LGUI(KC_LEFT))
#define CG_LOCK  LGUI(KC_L)
#define ALT_SPC  LALT(KC_SPC)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
    case MY_ARW:
      if(record->event.pressed) {
        SEND_STRING("->");
      }
      break;
    case MY_DARW:
      if(record->event.pressed) {
        SEND_STRING("=>");
      }
      break;
    default:
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    KC_Q     ,  KC_W     ,  KC_E     ,  KC_R     ,  KC_T     ,                               KC_Y     ,  KC_U     ,  KC_I     ,  KC_O     ,  KC_P     ,
    KC_A     ,  KC_S     ,  KC_D     ,  KC_F     ,  KC_G     ,                               KC_H     ,  KC_J     ,  KC_K     ,  KC_L     ,  KC_SCLN  ,
    LSHIFT_Z ,  KC_X     ,  KC_C     ,  KC_V     ,  KC_B     ,                               KC_N     ,  KC_M     ,  KC_COMM  ,  KC_DOT   ,  KC_SLSH  ,
    KC_LCTL  ,  KC_LGUI  ,  KC_LALT  ,  KC_BSPC  ,  MO(1)    ,  LY3_SPC  ,      KC_ENT    ,  MO(2)    ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,  KC_TAB
    ),

  [1] = LAYOUT_universal(
    KC_1     ,  KC_2     ,  KC_3     ,  KC_4     ,  KC_5    ,                               KC_6     ,  KC_7     ,  KC_8     ,  KC_9      ,  KC_0     ,
    S(KC_1)  ,  S(KC_2)  ,  S(KC_3)  ,  S(KC_4)  ,  S(KC_5) ,                               KC_MINUS ,  KC_EQL   ,  S(KC_9)  ,  S(KC_0)   ,  KC_QUOT  ,
    XXXXXXX  , S(KC_LBRC), S(KC_RBRC),  XXXXXXX  ,  KC_ENT  ,                             S(KC_MINUS),  KC_GRV   ,  KC_LBRC  ,  KC_RBRC   ,  KC_BSLS  ,
    _______  ,  _______  ,  _______  ,  _______  ,  _______ ,  _______  ,       _______  ,  MO(3)    ,  _______  ,  _______  ,  _______   , _______
    ),

  [2] = LAYOUT_universal(
    _______  ,  _______  ,  _______  ,  _______  ,  _______  ,                              _______  ,  MY_ARW   ,  MY_DARW  ,  _______  ,  _______  ,
    KC_ESC   ,  XXXXXXX  ,  KC_BTN3  ,  KC_BTN1  ,  KC_BTN2  ,                              KC_LEFT  ,  KC_DOWN  ,  KC_UP    ,  KC_RIGHT ,  _______  ,
    _______  ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,  XXXXXXX  ,                              KC_HOME  ,  KC_PGUP  ,  KC_PGDN  ,  KC_END   ,  _______  ,
    _______  ,  _______  ,  _______  ,  KC_DEL   ,  MO(3)    ,  _______  ,      _______  ,  _______  ,  _______  ,  _______  ,  _______  , KC_RIGHT_SHIFT
    ),


  [3] = LAYOUT_universal(
    KC_F1    ,  KC_F2    ,  KC_F3    ,  KC_F4    ,  KC_F5    ,                              KC_F6    ,  KC_F7    ,  KC_F8    ,  KC_F9    ,  KC_F10  ,
    _______  ,  KC_BTN3  ,  KC_BTN2  ,  KC_BTN1  ,  _______  ,                              _______  ,  KC_BTN1  ,  KC_BTN2  ,  KC_BTN3  ,  KC_F11  ,
    _______  ,  _______  ,  KC_BTN5  ,  KC_BTN4  ,  _______  ,                              _______  ,  KC_BTN4  ,  KC_BTN5  ,  _______  ,  KC_F12  ,
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
    // Auto enable scroll mode when the highest layer is 3C
    keyball_set_scroll_mode(get_highest_layer(state) == 1);
    return state;
}

/**
 * combo
 */
const uint16_t PROGMEM combo_w_e[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_i_o[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combo_comm_dot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_x_c[]    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_f_d[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_f_s[] = {KC_F, KC_S, COMBO_END};
const uint16_t PROGMEM combo_s_d[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_a_f[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo_k_j[] = {KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_l_j[] = {KC_L, KC_J, COMBO_END};
const uint16_t PROGMEM combo_l_k[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM combo_scln_j[] = {KC_SCLN, KC_J, COMBO_END};
const uint16_t PROGMEM combo_o_p[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_g_b[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM combo_w_q[] = {KC_W, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_s_d_f[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_l_k_j[] = {KC_L, KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_a_s_d_f[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_scln_l_k_j[] = {KC_SCLN, KC_L, KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM combo_f_j[] = {KC_F, KC_J, COMBO_END};

enum combo_events {
  COMBO_ESC1 = COMBO_SAFE_RANGE,
  COMBO_ESC2,
  COMBO_IME_ON,
  COMBO_IME_OFF,
  COMBO_BSPC,
  COMBO_TAB,
  COMBO_CAPS,
};

combo_t key_combos[] = {
  [COMBO_HRC_L_CTL] = COMBO(combo_f_d, HRC_L_CTL),
  [COMBO_HRC_L_SFT] = COMBO(combo_f_s, HRC_L_SFT),
  [COMBO_HRC_L_ALT] = COMBO(combo_s_d, HRC_L_ALT),
  [COMBO_HRC_L_GUI] = COMBO(combo_a_f, HRC_L_GUI),
  [COMBO_HRC_R_CTL] = COMBO(combo_k_j, HRC_R_CTL),
  [COMBO_HRC_R_SFT] = COMBO(combo_l_j, HRC_R_SFT),
  [COMBO_HRC_R_ALT] = COMBO(combo_l_k, HRC_R_ALT),
  [COMBO_HRC_R_GUI] = COMBO(combo_scln_j, HRC_R_GUI),

  [COMBO_ESC1] = COMBO_ACTION(combo_w_e),
  [COMBO_ESC2] = COMBO_ACTION(combo_i_o),
  [COMBO_IME_ON] = COMBO(combo_comm_dot, KC_LNG2),
  [COMBO_IME_OFF] = COMBO_ACTION(combo_x_c),

  [COMBO_BSPC] = COMBO(combo_o_p, KC_BSPC),
  [COMBO_CAPS] = COMBO(combo_g_b, CW_TOGG),
  [COMBO_CAPS] = COMBO(combo_f_j, CW_TOGG),
  [COMBO_TAB] = COMBO(combo_w_q, KC_TAB),
  [COMBO_HRC_L_CTL_SFT] = COMBO(combo_s_d_f, HRC_L_CTL_SFT),
  [COMBO_HRC_R_CTL_SFT] = COMBO(combo_l_k_j, HRC_R_CTL_SFT),
  [COMBO_HRC_L_CTL_ALT] = COMBO(combo_a_s_d_f, HRC_L_CTL_ALT),
  [COMBO_HRC_R_CTL_ALT] = COMBO(combo_scln_l_k_j, HRC_R_CTL_ALT),
};

// clang-format on
void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_ESC1:
        case COMBO_ESC2:
            if (pressed) {
                tap_code(KC_LNG2);
                caps_word_off();
                register_code(KC_ESC);
            } else {
                unregister_code(KC_ESC);
            }
            break;
        case COMBO_IME_OFF:
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
