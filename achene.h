
#pragma once

#include "quantum.h"

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report);

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record);
