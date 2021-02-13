/*!
 * @file radsens.h
 *
 * BSD license, all text here must be included in any redistribution.
 * See the LICENSE file for details.
 *
 */

#ifndef RADSENS_H_
#define RADSENS_H_

#include <Arduino.h>

class RadSens {
public:
    RadSens();
    ~RadSens();
    bool init();
    bool readData();
    float getRadiationStatic() const;

private:
    uint8_t *data;
};

#endif /* RADSENS_H_ */
