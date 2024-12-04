
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
  // ╭──────────────────────────────────────────────────╮   ╭────────────────────────────────────────────────────╮
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  // ├──────────────────────────────────────────────────┤   ├────────────────────────────────────────────────────┤
      CW_TOGG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
  // ├──────────────────────────────────────────────────┤   ├────────────────────────────────────────────────────┤
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_RBRC,
  // ├──────────────────────────────────────────────────┤   ├────────────────────────────────────────────────────┤
      KC_GRV,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────┤   ├────────────────────────────────────────────────────╯
                           CTL_ENT, SFT_SPC, RAISE_BSPC,       KC_LALT, LOWER_ESC,
                                       XXXXXXX, XXXXXXX,       XXXXXXX
  //              ╰─────────────────────────────────────╯   ╰──────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              CTL_ENT, SFT_SPC, RAISE_BSPC,    KC_LALT, LOWER_ESC,
                                          XXXXXXX, XXXXXXX,    XXXXXXX
  //                 ╰─────────────────────────────────────╯ ╰──────────────────────╯
  ),
  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                              CTL_ENT, SFT_SPC, RAISE_BSPC,    KC_LALT, LOWER_ESC,
                                          XXXXXXX, XXXXXXX,    XXXXXXX
  //                 ╰─────────────────────────────────────╯ ╰──────────────────────╯
  ),
  [LAYER_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, CARET_HORZ, CARET, CARET_VERT, CPI_UP,        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, SCROLL_HORZ, SCROLL, SCROLL_VERT, CPI_DOWN,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                     CTL_ENT, SFT_SPC, RAISE_BSPC,    KC_LALT, LOWER_ESC,
                                                 XXXXXXX, XXXXXXX,    XXXXXXX
  //                 ╰─────────────────────────────────────────────╯ ╰──────────────────────╯
  ),
};
