
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


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_Q,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_A,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_Q,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_A,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_Q,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_A,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
          CTL_ENT, SFT_SPC, RAISE_BSPC,  KC_A,    KC_A,    KC_A
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
      KC_Q,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_A,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_Q,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,KC_A,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      KC_Q,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,KC_A,
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
