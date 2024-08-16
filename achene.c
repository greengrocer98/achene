#include <math.h>

#include "achene.h"

enum trackball_status {
    ACCEL,
    SCROLLING,
};

int      status      = ACCEL;
int      accel_level = 1;
uint16_t current_cpi;
int16_t  scroll_buffer = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    switch (status) {
        case ACCEL:
            set_accel_curve(&mouse_report, accel_level);
            break;
        case SCROLLING:
            scroll_apps(&mouse_report);
        default:
            break;
    }
    return mouse_report;
}

// Function to handle key events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ACCEL_0:
            accel_level = 0;
            break;
        case ACCEL_1:
            accel_level = 1;
            break;
        case CPI_UP:
            current_cpi = pointing_device_get_cpi();
            if (current_cpi < 12000 + CPI_STEP) {
                pointing_device_set_cpi(current_cpi + CPI_STEP);
            }
            break;
        case CPI_DOWN:
            current_cpi = pointing_device_get_cpi();
            if (current_cpi > 100 + CPI_STEP) {
                pointing_device_set_cpi(current_cpi - CPI_STEP);
            }
            break;
        case SCROLL_APPS:
            if (record->event.pressed) {
                status = SCROLLING;
                register_code(KC_LALT);
                tap_code(KC_TAB);
            } else {
                if (status == SCROLLING) {
                    status = ACCEL;
                    unregister_code(KC_LALT);
                }
            }
        default:
            break;
    }
    return true;
}

void set_accel_curve(report_mouse_t *mouse_report, int accel_level) {
    int   x;
    int   y;
    float magnitude;
    switch (accel_level) {
        case 0:
            /* go without changing */
            break;
        case 1:
            /* custom accelaration curve */
            x = mouse_report->x;
            y = mouse_report->y;

            magnitude = pow(x * x + y * y, 0.2);

            mouse_report->x = (int8_t)(x * magnitude);
            mouse_report->y = (int8_t)(y * magnitude);
            break;
        default:
            break;
    }
}

void scroll_apps(report_mouse_t *mouse_report) {
    scroll_buffer += mouse_report->x;
    if (abs(scroll_buffer) > SCROLL_BUFFER_SIZE) {
        tap_code16(scroll_buffer > 0 ? KC_TAB : LSFT(KC_TAB));
        scroll_buffer = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCROLL_APPS:
            return true;
        default:
            return false;
    }
    return is_mouse_record_user(keycode, record);
}