#include <math.h>

#include "achene.h"

enum trackball_status {
    ACCEL,
    SCROLL,
};

uint8_t  accel_level = 1;
uint16_t current_cpi;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    set_accel_curve(&mouse_report, accel_level);
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
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
            default:
                break;
        }
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
