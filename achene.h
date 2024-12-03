
#pragma once

#include "quantum.h"

#define CPI_STEP 100
#define SCROLL_WINS_BUF_SIZE 450
#define MOVE_WINS_BUF_SIZE 350
#define SCROLL_BUF_SIZE 40

typedef struct {
    int status;
    int x_buf;
    int y_buf;
} trackball;

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_MOUSE,
};

enum trackball_keycodes {
    #ifdef VIAL_ENABLE
        ACCEL_0 = QK_KB_0,
    #else
        ACCEL_0 = SAFE_RANGE,
    #endif
    ACCEL_1,
    CPI_UP,
    CPI_DOWN,
    SCROLL_WINS,
    SCROLL,
    MOVE_WINS,
};

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void scroll_windows(report_mouse_t *mouse_report, trackball *achene);

void scroll_vert(report_mouse_t *mouse_report, trackball *achene);

void move_windows(report_mouse_t *mouse_report, trackball *achene);