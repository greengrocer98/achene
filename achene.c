#include <math.h>

#include "achene.h"

enum trackball_status {
    ACCEL,
    SCROLL,
};

struct trackball
{
    int status;
    int accel_level;
    int scroll;
};
struct trackball sensor = {ACCEL, 0, 0};

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    switch (sensor.status)
    {
    case ACCEL:
        set_accel_curve(&mouse_report, sensor.accel_level);
        break;
    case SCROLL:
        set_scroll(&mouse_report, sensor.scroll);
    default:
        break;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ACCEL_1:
            if (record->event.pressed) {
                sensor.status = ACCEL;
                sensor.accel_level = 1;
            }
            break;
        case SCROLL_V:
            if (record->event.pressed) {
                sensor.status = SCROLL;
                sensor.scroll = 0;
            } else {
                sensor.status = ACCEL;
            }
            break;
        case SCROLL_H:
            if (record->event.pressed) {
                sensor.status = SCROLL;
                sensor.scroll = 1;
            } else {
                sensor.status = ACCEL;
            }
            break;
        default:
            break;
    }
    return true;
}

void set_accel_curve(report_mouse_t *mouse_report, int accel_level) {
    int x;
    int y;
    float magnitude;

    x = mouse_report->x;
    y = mouse_report->y;

    magnitude = pow(x*x+y*y, 0.4);

    mouse_report->x = x*magnitude;
    mouse_report->y = y*magnitude;
}


void set_scroll(report_mouse_t *mouse_report, int scroll_direction) {

}