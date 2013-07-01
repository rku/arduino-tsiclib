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

#ifndef TSIC_H
#define TSIC_H  1

#include <inttypes.h>
#include "Arduino.h"

class TSIC
{
public:
    explicit TSIC(uint8_t vcc_pin, uint8_t signal_pin);
    float readTemperature() const;
private:
    uint8_t readByte() const;

    uint8_t m_vcc_pin;
    uint8_t m_signal_pin;
};

#endif /* TSIC_H */
