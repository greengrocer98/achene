
#include QMK_KEYBOARD_H
#include "achene.h"

#define LOWER_ESC LT(LAYER_LOWER, KC_ESC)
#define RAISE_BSPC LT(LAYER_RAISE, KC_BSPC)

#define CTL_ENT LCTL_T(KC_ENT)
#define SFT_SPC LSFT_T(KC_SPC)
#define GUI_GRAVE LGUI_T(KC_GRAVE)
#define ALT_BSPC LALT_T(KC_BSPC)
#define GUI_DEL LGUI_T(KC_DEL)

#define OSM_S OSM(MOD_LSFT)
#define OSM_C OSM(MOD_LCTL)
#define OSM_G OSM(MOD_LGUI)
#define OSM_A OSM(MOD_LALT)

enum combos {
  JK,
  UI,
  MCOM,
  DF,
  ER,
  CV,
  KL,
};

const uint16_t PROGMEM jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM mcom[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM kl[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
  [JK] = COMBO(jk, KC_LALT),
  [UI] = COMBO(ui, S(KC_9)),
  [MCOM] = COMBO(mcom, KC_LBRC),
  [DF] = COMBO(df, KC_TAB),
  [ER] = COMBO(er, S(KC_0)),
  [CV] = COMBO(cv, KC_RBRC),
  [KL] = COMBO(kl, KC_QUOT),
};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
          CTL_ENT, SFT_SPC, RAISE_BSPC,  XXXXXXX,    XXXXXXX,    LOWER_ESC
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
          CTL_ENT, SFT_SPC, RAISE_BSPC,  XXXXXXX,    XXXXXXX,    LOWER_ESC
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),
  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
          CTL_ENT, SFT_SPC, RAISE_BSPC,  XXXXXXX,    XXXXXXX,    LOWER_ESC
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),
  [LAYER_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      XXXXXXX,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      XXXXXXX,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
          CTL_ENT, SFT_SPC, RAISE_BSPC,  XXXXXXX,    XXXXXXX,    LOWER_ESC
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),
};
