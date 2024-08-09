
#pragma once

#include "quantum.h"

#define CPI_STEP 100

enum trackball_keycodes {
    ACCEL_0 = SAFE_RANGE,
    ACCEL_1,
    CPI_UP,
    CPI_DOWN,
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report);

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void set_scroll(report_mouse_t *mouse_report, int scroll_direction);