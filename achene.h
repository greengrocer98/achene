
#pragma once

#include "quantum.h"

#define CPI_STEP 100
#define SCROLL_APPS_BUF_SIZE 400
#define SCROLL_VERT_BUF_SIZE 40

enum trackball_keycodes {
    ACCEL_0 = SAFE_RANGE,
    ACCEL_1,
    CPI_UP,
    CPI_DOWN,
    SCROLL_APPS,
    SCROLL_VERT,
};

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void scroll_apps(report_mouse_t *mouse_report, int *buf);

void scroll_vert(report_mouse_t *mouse_report, int *buf);