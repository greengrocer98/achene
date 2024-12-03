#include <math.h>

#include "achene.h"

enum trackball_status {
    MOUSE,
    SCRL_WINS,
    SCRL,
    MV_WINS,
};

trackball achene_trackball = {.status = MOUSE, .x_buf = 0, .y_buf = 0};
int      status      = MOUSE;
int      accel_level = 0;
uint16_t current_cpi;
int      scroll_apps_buf = 0;
int      scroll_vert_buf = 0;
int      move_buf_x      = 0;
int      move_buf_y      = 0;

// Function to enable auto mouse layer
void pointing_device_init_user(void) {
    set_auto_mouse_layer(LAYER_MOUSE);
    set_auto_mouse_enable(true);
}

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    switch (achene_trackball.status) {
        case SCRL_WINS:
            scroll_windows(&mouse_report, &achene_trackball);
            break;
        case SCRL:
            scroll_vert(&mouse_report, &achene_trackball);
            break;
        case MV_WINS:
            move_windows(&mouse_report, &achene_trackball);
            break;
        default:
            break;
    }
    return mouse_report;
}

// Function to handle key events
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case SCROLL_WINS:
            if (record->event.pressed) {
                achene_trackball.status = SCRL_WINS;
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf = 0;
                achene_trackball.y_buf = 0;
            }
            break;
        case SCROLL:
            if (record->event.pressed) {
                achene_trackball.status = SCRL;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf = 0;
                achene_trackball.y_buf = 0;
            }
            break;
        case MOVE_WINS:
            if (record->event.pressed) {
                achene_trackball.status = MV_WINS;
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf = 0;
                achene_trackball.y_buf = 0;
            }
            break;
        default:
            break;
    }
    return true;
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SCROLL_WINS:
            return true;
        case SCROLL:
            return true;
        case MOVE_WINS:
            return true;
        default:
            return false;
    }
    return is_mouse_record_user(keycode, record);
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

void scroll_windows(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    if (abs(achene->x_buf) > SCROLL_WINS_BUF_SIZE) {
        tap_code16(achene->x_buf > 0 ? KC_TAB : LSFT(KC_TAB));
        achene->x_buf = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void scroll_vert(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    achene->y_buf += mouse_report->y;
    if (abs(achene->y_buf) > SCROLL_BUF_SIZE) {
        mouse_report->v = achene->y_buf > 0 ? 1 : -1;
        achene->y_buf            = 0;
    }
    if (abs(achene->x_buf) > SCROLL_BUF_SIZE) {
        mouse_report->h = achene->x_buf > 0 ? 1 : -1;
        achene->x_buf            = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void move_windows(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    achene->y_buf += mouse_report->y;
    if (abs(achene->x_buf) > MOVE_WINS_BUF_SIZE) {
        tap_code16(achene->x_buf > 0 ? KC_RIGHT : KC_LEFT);
        achene->x_buf = 0;
    }
    if (abs(achene->y_buf) > MOVE_WINS_BUF_SIZE) {
        tap_code16(achene->y_buf > 0 ? KC_DOWN : KC_UP);
        achene->y_buf = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}