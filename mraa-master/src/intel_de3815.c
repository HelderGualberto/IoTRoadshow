/*
 * Author: Thomas Ingleby <thomas.c.ingleby@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "intel_de3815.h"

#define MAX_SIZE 64
#define SYSFS_CLASS_GPIO "/sys/class/gpio"

mraa_board_t*
mraa_intel_de3815()
{
    mraa_board_t* b = (mraa_board_t*) malloc(sizeof(mraa_board_t));
    if (b == NULL)
        return NULL;

    b->phy_pin_count = 18;
    //b->gpio_count = 14;
    b->aio_count = 0;
    b->adc_raw = 0;
    b->adc_supported = 0;
    b->pwm_default_period = 500;
    b->pwm_max_period = 2147483;
    b->pwm_min_period = 1;

    b->pins = (mraa_pininfo_t*) malloc(sizeof(mraa_pininfo_t)*MRAA_INTEL_DE3815_PINCOUNT);

    strncpy(b->pins[0].name, "1.8v", 8);
    b->pins[0].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};

    strncpy(b->pins[1].name, "GND", 8);
    b->pins[1].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[2].name, "HDMIcec", 8);
    b->pins[2].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[3].name, "DMICclk", 8);
    b->pins[3].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[4].name, "3.3v", 8);
    b->pins[4].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[5].name, "DMICda", 8);
    b->pins[5].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[6].name, "Key", 8);
    b->pins[6].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[7].name, "SMB-A", 8);
    b->pins[7].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[8].name, "5v", 8);
    b->pins[8].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[9].name, "SCI", 8);
    b->pins[9].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};

    strncpy(b->pins[10].name, "PWM0", 8);
    b->pins[10].capabilites = (mraa_pincapabilities_t) {1,0,1,0,0,0,0,0};
    b->pins[10].pwm.pinmap = 0;
    b->pins[10].pwm.parent_id = 0;
    b->pins[10].pwm.mux_total = 0;

    strncpy(b->pins[11].name, "PWM1", 8);
    b->pins[11].capabilites = (mraa_pincapabilities_t) {1,0,1,0,0,0,0,0};
    b->pins[11].pwm.pinmap = 0;
    b->pins[11].pwm.parent_id = 1;
    b->pins[11].pwm.mux_total = 0;

    strncpy(b->pins[12].name, "I2C0-SCL", 8);
    b->pins[12].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,1,0,0};
    b->pins[12].i2c.pinmap = 1;
    b->pins[12].i2c.mux_total = 0;

    strncpy(b->pins[13].name, "I2C0-SDA", 8);
    b->pins[13].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,1,0,0};
    b->pins[13].i2c.pinmap = 1;
    b->pins[13].i2c.mux_total = 0;

    strncpy(b->pins[14].name, "I2C1-SCL", 8);
    b->pins[14].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,1,0,0};
    b->pins[14].i2c.pinmap = 1;
    b->pins[14].i2c.mux_total = 0;

    strncpy(b->pins[15].name, "I2C1-SDA", 8);
    b->pins[15].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,1,0,0};
    b->pins[15].i2c.pinmap = 1;
    b->pins[15].i2c.mux_total = 0;

    strncpy(b->pins[16].name, "SMB_CLK", 8);
    b->pins[16].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};
    strncpy(b->pins[17].name, "SMB_SDA", 8);
    b->pins[17].capabilites = (mraa_pincapabilities_t) {1,0,0,0,0,0,0,0};

    //BUS DEFINITIONS
    b->i2c_bus_count = 2;
    b->def_i2c_bus = 0;
    b->i2c_bus[0].bus_id = 0;
    b->i2c_bus[0].sda = 12;
    b->i2c_bus[0].scl = 13;

    b->i2c_bus[1].bus_id = 1;
    b->i2c_bus[1].sda = 14;
    b->i2c_bus[1].scl = 15;

    b->spi_bus_count = 1;
    b->def_spi_bus = 0;
    b->spi_bus[0].bus_id = 1;
    b->spi_bus[0].slave_s = 0;
    b->spi_bus[0].cs = 10;
    b->spi_bus[0].mosi = 11;
    b->spi_bus[0].miso = 12;
    b->spi_bus[0].sclk = 13;

    return b;
}
