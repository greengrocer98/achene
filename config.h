#pragma once

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP16
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

/* Master half */
#define MASTER_RIGHT
#define SOFT_SERIAL_PIN GP0
#define SPLIT_POINTING_ENABLE

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP4
#define POINTING_DEVICE_RIGHT
#define PMW33XX_CS_PIN GP5

#define PMW33XX_CPI 800             // The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.
#define PMW33XX_CLOCK_SPEED 2000000 // Sets the clock speed that the sensor runs at. Defaults to 2000000
#define MOUSE_EXTENDED_REPORT       // Use -32767 to 32767, instead of just -127 to 127.

/* Trackball adjustment. */
#define POINTING_DEVICE_ROTATION_180
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

/* Mouse scroll adjustment. */
#define MOUSEKEY_WHEEL_INTERVAL 150
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_DELTA 1
#define MOUSEKEY_WHEEL_TIME_TO_MAX 120
#define MOUSEKEY_WHEEL_MAX_SPEED 8