
#pragma once

#include "quantum.h"

#define CPI_STEP 100
#define SCROLL_WINS_BUF_SIZE 450
#define MOVE_WINS_BUF_SIZE 350
#define SCROLL_BUF_SIZE 40
#define CARET_BUF_SIZE 20

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
    CPI_UP = SAFE_RANGE,
    CPI_DOWN,
    SCROLL_WINS,
    SCROLL,
    SCROLL_VERT,
    SCROLL_HORZ,
    MOVE_WINS,
    CARET,
    CARET_VERT,
    CARET_HORZ
};

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void scroll_windows(report_mouse_t *mouse_report, trackball *achene);

void scroll(report_mouse_t *mouse_report, trackball *achene);

void scroll_vert(report_mouse_t *mouse_report, trackball *achene);

void scroll_horz(report_mouse_t *mouse_report, trackball *achene);

void caret(report_mouse_t *mouse_report, trackball *achene);

void caret_vert(report_mouse_t *mouse_report, trackball *achene);

void caret_horz(report_mouse_t *mouse_report, trackball *achene);

void move_windows(report_mouse_t *mouse_report, trackball *achene);