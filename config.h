#pragma once

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP16
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

/* SPI & PMW3360 settings. */
// #define SPI_DRIVER SPID0
#define PMW33XX_CS_PIN GP1
#define SPI_SCK_PIN GP2
#define SPI_MOSI_PIN GP3
#define SPI_MISO_PIN GP4

#define PMW33XX_CPI 600      // The CPI range is 100-12000, in increments of 100. Defaults to 1600 CPI.
#define PMW33XX_CLOCK_SPEED 2000000 // Sets the clock speed that the sensor runs at. Defaults to 2000000
#define MOUSE_EXTENDED_REPORT // Use -32767 to 32767, instead of just -127 to 127.
// #define POINTING_DEVICE_TASK_THROTTLE_MS 10

/* Trackball adjustment. */
#define ROTATIONAL_TRANSFORM_ANGLE -90
#define POINTING_DEVICE_INVERT_X
