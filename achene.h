
#pragma once

#include "quantum.h"

#define CPI_STEP 100
#define SCROLL_WINS_BUF_SIZE 450
#define MOVE_WINS_BUF_SIZE 350
#define SCROLL_VERT_BUF_SIZE 40

enum keymap_layers {
    LAYER_BASE = 0,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_MOUSE,
};

enum trackball_keycodes {
    ACCEL_0 = SAFE_RANGE,
    ACCEL_1,
    CPI_UP,
    CPI_DOWN,
    SCROLL_WINS,
    SCROLL_VERT,
    MOVE_WINS,
};

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void scroll_windows(report_mouse_t *mouse_report, int *buf);

void scroll_vert(report_mouse_t *mouse_report, int *buf);

void move_windows(report_mouse_t *mouse_report, int *buf_x, int *buf_y);