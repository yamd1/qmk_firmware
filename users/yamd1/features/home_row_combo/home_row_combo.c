#include "yamd1.h"

// enum HRCM_STATE {
//     HRCM_STATE_NONE  = 0,
//     HRCM_STATE_L_CTL = 1,
//     HRCM_STATE_L_ALT = 2,
//     HRCM_STATE_R_CTL = 4,
//     HRCM_STATE_R_ALT = 8,
// };

// static uint8_t hrcm_state = HRCM_STATE_NONE;

bool process_home_row_combo(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
    //     case HRC_L_CTL:
    //         if (record->tap.count && record->event.pressed) {
    //             set_oneshot_mods(MOD_LCTL);
    //             return false;
    //         } else if (record->event.pressed) {
    //             register_code(KC_LCTL);
    //             hrcm_state |= HRCM_STATE_L_CTL;
    //         } else {
    //             unregister_code(KC_LCTL);
    //             hrcm_state &= ~HRCM_STATE_L_CTL;
    //         }
    //         break;
    //     case HRC_L_ALT:
    //         if (record->tap.count && record->event.pressed) {
    //             set_oneshot_mods(MOD_LALT);
    //             return false;
    //         } else if (record->event.pressed) {
    //             register_code(KC_LALT);
    //             hrcm_state |= HRCM_STATE_L_ALT;
    //         } else {
    //             unregister_code(KC_LALT);
    //             hrcm_state &= ~HRCM_STATE_L_ALT;
    //         }
    //         break;
    //     case HRC_R_CTL:
    //         if (record->tap.count && record->event.pressed) {
    //             set_oneshot_mods(MOD_LCTL);
    //             return false;
    //         } else if (record->event.pressed) {
    //             register_code(KC_LCTL);
    //             hrcm_state |= HRCM_STATE_R_CTL;
    //         } else {
    //             unregister_code(KC_LCTL);
    //             hrcm_state &= ~HRCM_STATE_R_CTL;
    //         }
    //         break;
    //     case HRC_R_ALT:
    //         if (record->tap.count && record->event.pressed) {
    //             set_oneshot_mods(MOD_LALT);
    //             return false;
    //         } else if (record->event.pressed) {
    //             register_code(KC_LALT);
    //             hrcm_state |= HRCM_STATE_R_ALT;
    //         } else {
    //             unregister_code(KC_LALT);
    //             hrcm_state &= ~HRCM_STATE_R_ALT;
    //         }
    //         break;
    //     default:
    //         break;
    // }
    return true;
}