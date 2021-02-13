/*!
 * @file radsens.h
 *
 * BSD license, all text here must be included in any redistribution.
 * See the LICENSE file for details.
 *
 */

#include <Wire.h>

#include "radsens.h"

static const uint8_t I2C_DEFAULT_ADDRESS = 0x66;
static const uint8_t DATA_SIZE = 19;

RadSens::RadSens() :
    data(new uint8_t[DATA_SIZE])
{
}

RadSens::~RadSens() {
    delete[] data;
}

bool RadSens::init() {
    Wire.begin();
    Wire.beginTransmission(I2C_DEFAULT_ADDRESS);
    if (Wire.endTransmission() != 0)
        return false;
    if (!readData())
        return false;
    if (data[0] != 0x7D)
        return false;
    return true;
}

bool RadSens::readData() {
    if (Wire.requestFrom(I2C_DEFAULT_ADDRESS, DATA_SIZE) != DATA_SIZE)
        return false;
    for (uint8_t i = 0; i < DATA_SIZE; i++)
        data[i] = Wire.read();
    return true;
}

float RadSens::getRadiationStatic() const {
    return (uint32_t)((data[6] << 16) | (data[7] << 8) | data[8]) / 10.0;
}
