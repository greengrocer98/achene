
#include QMK_KEYBOARD_H
#include "achene.h"

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_MOUSE,
};

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

// enum combos {
//   JK,
//   UI,
//   MCOM,
//   DF,
//   ER,
//   CV,
//   KL,
//   SD,
//   SF,
// };

// const uint16_t PROGMEM jk[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM ui[] = {KC_U, KC_I, COMBO_END};
// const uint16_t PROGMEM mcom[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM df[] = {KC_D, KC_F, COMBO_END};
// const uint16_t PROGMEM er[] = {KC_E, KC_R, COMBO_END};
// const uint16_t PROGMEM cv[] = {KC_C, KC_V, COMBO_END};
// const uint16_t PROGMEM kl[] = {KC_K, KC_L, COMBO_END};
// const uint16_t PROGMEM sd[] = {KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM sf[] = {KC_S, KC_F, COMBO_END};

// combo_t key_combos[] = {
//   [JK] = COMBO(jk, KC_LALT),
//   [UI] = COMBO(ui, S(KC_9)),
//   [MCOM] = COMBO(mcom, KC_LBRC),
//   [DF] = COMBO(df, KC_TAB),
//   [ER] = COMBO(er, S(KC_0)),
//   [CV] = COMBO(cv, KC_RBRC),
//   [KL] = COMBO(kl, KC_QUOT),
//   [SD] = COMBO(sd, SCROLL_APPS),
//   [SF] = COMBO(sf, SCROLL_VERT),
// };


// Function to enable auto mouse layer
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_MOUSE);
    set_auto_mouse_enable(true);
}

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
                    CTL_ENT, SFT_SPC, RAISE_BSPC,                  LOWER_ESC
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_LOWER] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, KC_DEL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, CW_TOGG,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
      S(KC_BSLS), S(KC_EQL), KC_EQL, KC_MINS, KC_DOT,   KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_BSLS,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                      CTL_ENT, SFT_SPC, ALT_BSPC,                   _______
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    S(KC_9), KC_LBRC, KC_RBRC, S(KC_0), CPI_UP,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_LGUI,   OSM_C,   OSM_S,   OSM_A,  OSM_G,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,   S(KC_LALT), XXXXXXX, XXXXXXX, XXXXXXX, CPI_DOWN,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, XXXXXXX, _______,                 KC_LSFT
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
         KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
         KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, 
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    KC_WH_L, XXXXXXX, KC_WH_U, KC_WH_R, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        CTL_ENT, SFT_SPC, ALT_BSPC,                 XXXXXXX
  //              ╰────────────────────────────────╯ ╰──────────────────────╯
  ),
};
