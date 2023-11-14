#pragma once

#include "quantum.h"
#include "transactions.h"

// #ifdef HOME_ROW_COMBO_EBABLE
#define HRC_L_CTL OSM(MOD_LCTL)
#define HRC_L_SFT OSM(MOD_LSFT)
#define HRC_L_ALT OSM(MOD_LALT)
#define HRC_L_GUI OSM(MOD_LGUI)
#define HRC_R_CTL OSM(MOD_RCTL)
#define HRC_R_SFT OSM(MOD_RSFT)
#define HRC_R_ALT OSM(MOD_RALT)
#define HRC_R_GUI OSM(MOD_RGUI)
#define HRC_L_CTL_SFT OSM(MOD_LCTL | MOD_LSFT)
#define HRC_R_CTL_SFT OSM(MOD_RCTL | MOD_RSFT)

// #endif

enum userspace_combo_events {
    // #ifdef HOME_ROW_COMBO_EBABLE
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
    // #endif

    COMBO_SAFE_RANGE,
};
