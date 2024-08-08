
#pragma once

#include "quantum.h"

enum trackball_keycodes {
    ACCEL_1 = SAFE_RANGE,
    SCROLL_V,
    SCROLL_H,
};

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report);

bool process_record_user(uint16_t keycode, keyrecord_t *record);

void set_accel_curve(report_mouse_t *mouse_report, int accel_level);

void set_scroll(report_mouse_t *mouse_report, int scroll_direction);