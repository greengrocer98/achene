
#include QMK_KEYBOARD_H
#include "achene.h"

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
};

#define LOWER LT(LAYER_LOWER, KC_ESC)
#define RAISE LT(LAYER_RAISE, KC_TAB)

#define CTL_ENT LCTL_T(KC_ENT)
#define SFT_SPC LSFT_T(KC_SPC)
#define GUI_BSPC LGUI_T(KC_BSPC)
#define ALT_DEL LALT_T(KC_DEL)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                 CTL_ENT, SFT_SPC, GUI_BSPC, RAISE,   ALT_DEL,                      LOWER
  //           ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MUTE, KC_VOLD, KC_VOLD, KC_PSCR, KC_RBRC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, CW_TOGG,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      C(KC_BSLS), KC_GRV, KC_EQL, KC_MINS, KC_DOT,      KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
               CTL_ENT, SFT_SPC, GUI_BSPC, ALT_DEL,   XXXXXXX,                   _______
  //         ╰─────────────────────────────────────╯ ╰───────────────────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT, ACCEL_1, ACCEL_0, KC_RGHT, XXXXXXX,    KC_WH_D, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, 
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT,  CPI_UP, CPI_DOWN, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                XXXXXXX, _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
