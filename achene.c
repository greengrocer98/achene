#include <math.h>

#include "achene.h"

enum trackball_status {
    MOUSE,
    SCRL_APPS,
    SCRL_VERT,
};

int      status      = MOUSE;
int      accel_level = 1;
uint16_t current_cpi;
int      scroll_apps_buf = 0;
int      scroll_vert_buf = 0;

// Function to enable auto mouse layer
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_MOUSE);
    set_auto_mouse_enable(true);
}

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    switch (status) {
        case MOUSE:
            set_accel_curve(&mouse_report, accel_level);
            break;
        case SCRL_APPS:
            scroll_apps(&mouse_report, &scroll_apps_buf);
        case SCRL_VERT:
            scroll_vert(&mouse_report, &scroll_vert_buf);
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
                status = SCRL_APPS;
                register_code(KC_LALT);
            } else {
                status = MOUSE;
                unregister_code(KC_LALT);
            }
            break;
        case SCROLL_VERT:
            if (record->event.pressed) {
                status = SCRL_VERT;
            } else {
                status = MOUSE;
            }
            break;
        default:
            break;
    }
    return true;
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case SCROLL_APPS:
            return true;
        case SCROLL_VERT:
            return true;
        default:
            return false;
    }
    return  is_mouse_record_user(keycode, record);
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

void scroll_apps(report_mouse_t *mouse_report, int *buf) {
    *buf += mouse_report->x;
    if (abs(*buf) > SCROLL_APPS_BUF_SIZE) {
        tap_code16(*buf > 0 ? KC_TAB : LSFT(KC_TAB));
        *buf = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void scroll_vert(report_mouse_t *mouse_report, int *buf) {
    *buf += mouse_report->x;
    if (abs(*buf) > SCROLL_VERT_BUF_SIZE) {
        mouse_report->v = *buf > 0 ? 1 : -1;
        *buf            = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}