#include <math.h>

#include "achene.h"

enum trackball_status {
    MOUSE,
    SCRL_WINS,
    SCRL,
    SCRL_VERT,
    SCRL_HORZ,
    CRT,
    CRT_VERT,
    CRT_HORZ,
    MV_WINS,
};

trackball achene_trackball = {.status = MOUSE, .x_buf = 0, .y_buf = 0};
uint16_t  current_cpi;

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
            scroll(&mouse_report, &achene_trackball);
            break;
        case SCRL_VERT:
            scroll_vert(&mouse_report, &achene_trackball);
            break;
        case SCRL_HORZ:
            scroll_horz(&mouse_report, &achene_trackball);
            break;
        case CRT:
        case CRT_VERT:
            caret_vert(&mouse_report, &achene_trackball);
            break;
        case CRT_HORZ:
            caret_horz(&mouse_report, &achene_trackball);
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
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case SCROLL:
            if (record->event.pressed) {
                achene_trackball.status = SCRL;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case SCROLL_VERT:
            if (record->event.pressed) {
                achene_trackball.status = SCRL_VERT;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case SCROLL_HORZ:
            if (record->event.pressed) {
                achene_trackball.status = SCRL_HORZ;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case CARET:
            if (record->event.pressed) {
                achene_trackball.status = CRT;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case CARET_VERT:
            if (record->event.pressed) {
                achene_trackball.status = CRT_VERT;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case CARET_HORZ:
            if (record->event.pressed) {
                achene_trackball.status = CRT_HORZ;
            } else {
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        case MOVE_WINS:
            if (record->event.pressed) {
                achene_trackball.status = MV_WINS;
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                achene_trackball.status = MOUSE;
                achene_trackball.x_buf  = 0;
                achene_trackball.y_buf  = 0;
            }
            break;
        default:
            break;
    }
    return true;
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CPI_UP:
            return true;
        case CPI_DOWN:
            return true;
        case SCROLL_WINS:
            return true;
        case SCROLL:
            return true;
        case SCROLL_VERT:
            return true;
        case SCROLL_HORZ:
            return true;
        case MOVE_WINS:
            return true;
        case CARET:
            return true;
        case CARET_VERT:
            return true;
        case CARET_HORZ:
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

void scroll(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    achene->y_buf += mouse_report->y;
    if (abs(achene->y_buf) > SCROLL_BUF_SIZE) {
        mouse_report->v = achene->y_buf > 0 ? -1 : 1;
        achene->y_buf   = 0;
    }
    if (abs(achene->x_buf) > SCROLL_BUF_SIZE) {
        mouse_report->h = achene->x_buf > 0 ? 1 : -1;
        achene->x_buf   = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void scroll_vert(report_mouse_t *mouse_report, trackball *achene) {
    achene->y_buf += mouse_report->y;
    if (abs(achene->y_buf) > SCROLL_BUF_SIZE) {
        mouse_report->v = achene->y_buf > 0 ? -1 : 1;
        achene->y_buf   = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void scroll_horz(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    if (abs(achene->x_buf) > SCROLL_BUF_SIZE) {
        mouse_report->h = achene->x_buf > 0 ? 1 : -1;
        achene->x_buf   = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void caret(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    achene->y_buf += mouse_report->y;
    if (abs(achene->x_buf) > CARET_BUF_SIZE) {
        tap_code16(achene->x_buf > 0 ? KC_RIGHT : KC_LEFT);
        achene->x_buf = 0;
    }
    if (abs(achene->y_buf) > CARET_BUF_SIZE) {
        tap_code16(achene->y_buf > 0 ? KC_DOWN : KC_UP);
        achene->y_buf = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void caret_vert(report_mouse_t *mouse_report, trackball *achene) {
    achene->y_buf += mouse_report->y;
    if (abs(achene->y_buf) > CARET_BUF_SIZE) {
        tap_code16(achene->y_buf > 0 ? KC_DOWN : KC_UP);
        achene->y_buf = 0;
    }
    mouse_report->x = 0;
    mouse_report->y = 0;
}

void caret_horz(report_mouse_t *mouse_report, trackball *achene) {
    achene->x_buf += mouse_report->x;
    if (abs(achene->x_buf) > CARET_BUF_SIZE) {
        tap_code16(achene->x_buf > 0 ? KC_RIGHT : KC_LEFT);
        achene->x_buf = 0;
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