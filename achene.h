
#pragma once

#include "quantum.h"

#define CPI_STEP 100
#define SCROLL_BUFFER_SIZE 400

enum trackball_keycodes {
    ACCEL_0 = SAFE_RANGE,
    ACCEL_1,
    CPI_UP,
    CPI_DOWN,
    SCROLL_APPS,
};

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void scroll_apps(report_mouse_t *mouse_report);

void set_scroll(report_mouse_t *mouse_report, int scroll_direction);