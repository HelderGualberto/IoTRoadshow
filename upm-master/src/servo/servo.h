/*
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
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
#pragma once

#include <string>
#include <mraa/pwm.h>

namespace upm {

#define MIN_PULSE_WIDTH      600
#define MAX_PULSE_WIDTH      2500
#define MAX_PERIOD           7968

#define HIGH                  1
#define LOW                   0

/**
 * @brief servo libraries
 * @defgroup servo libupm-servo
 */
class Servo {
    public:
        /**
         * Instanciates a servo object
         *
         * @param pin servo pin number
         */
        Servo (int pin);

        /**
         * Servo object destructor.
         */
        ~Servo();

        /**
         * Set the of the servo engine.
         *
         * X = between (MIN_PULSE_WIDTH , MAX_PULSE_WIDTH)
         *
         * X usec
         * _______
         *        |_______________________________________
         *                      20000 usec
         *
         * Max period can be only 7968750(nses) which is ~8(msec)
         * so the servo will not work as expected.
         *
         * @param angle number between 0 and 180
         */
        mraa_result_t setAngle (int angle);

        /**
         * Return name of the component
         */
        std::string name()
        {
            return m_name;
        }

        /**
         * Set min pulse width
         *
         * @param width HIGH signal width
         */
        void setMinPulseWidth (int width);

        /**
         * Set max pulse width
         *
         * @param width HIGH signal width
         */
        void setMaxPulseWidth (int width);

        /**
         * Set max period width
         *
         * @param width PWM period width
         */
        void setMaxPeriod (int width);

        /**
         * Return min pulse width
         */
        int getMinPulseWidth ();

        /**
         * Return max pulse width
         */
        int getMaxPulseWidth ();

        /**
         * Return max PWM period width
         */
        int getMaxPeriod ();

    protected:
        int calcPulseTraveling (int value);

        std::string         m_name;
        int                 m_servoPin;
        float               m_maxAngle;
        mraa_pwm_context     m_pwmServoContext;
        int                 m_currAngle;

        int                 m_minPulseWidth;
        int                 m_maxPulseWidth;
        int                 m_maxPeriod;
};

}
