/**
 *  Library for reading TSIC digital temperature sensors like 305 and 206
 *  using the Arduino platform.
 *
 *  Copyright 2013 Rene Kuettner <rene@bitkanal.net>
 *
 *  Some portions of this code are based on code from Rolf W. available
 *  at [1] which is based on code from [2].
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  [1]: http://playground.arduino.cc/Code/Tsic
 *  [2]: http://www.mikrocontroller.net/topic/82087
 */

#include "TSIC.h"

#define TSIC_ON()   digitalWrite(m_vcc_pin, HIGH)
#define TSIC_OFF()  digitalWrite(m_vcc_pin, LOW)
#define TSIC_HIGH   digitalRead(m_signal_pin)
#define TSIC_LOW    !digitalRead(m_signal_pin)

TSIC::TSIC(uint8_t vcc_pin, uint8_t signal_pin)
    : m_vcc_pin(vcc_pin),
      m_signal_pin(signal_pin)
{
    // set up pins
    pinMode(m_vcc_pin, OUTPUT);
    pinMode(m_signal_pin, INPUT);
}

uint8_t TSIC::readByte() const
{
    uint16_t byte = 0;
    int parity = 0;

    while(TSIC_HIGH);
    while(TSIC_LOW);

    // read 8 bits and a parity bit
    for(int i = 0; i < 9; ++i) {

        while(TSIC_HIGH);
        delayMicroseconds(60);

        if(TSIC_HIGH) {
            byte |= 1 << (8 - i);
            ++parity;
        } else {
            while(TSIC_LOW);
        }
    }

    // check parity
    if(parity % 2) {
        return NAN;
    }

    return (uint8_t)(byte >> 1); // return byte without parity bit
}

float TSIC::readTemperature() const
{
    TSIC_ON();

    // wait for sensor to settle
    delayMicroseconds(60);

    // read two bytess
    uint8_t byte1 = readByte();
    uint8_t byte2 = readByte();

    TSIC_OFF();

    if(isnan(byte1) || isnan(byte2)) {
        // something went wrong
        return NAN;
    }

    float sensor_value = (byte1 << 8) | byte2;
    return (sensor_value / 2047.0f * 200.0f) - 50.0f; // from data sheet
}
