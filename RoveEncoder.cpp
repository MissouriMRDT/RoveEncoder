#include "RoveEncoder.h"

#define _USE_MATH_DEFINES
#include <cmath>


float RoveEncoder::boundDegrees0_360(float degrees) const {
    degrees = fmod(degrees, 360.0);
    if (m_allowNegativeDegrees) {
        if (degrees < -180) degrees += 360;
        if (degrees > 180) degrees -= 360;
        return degrees;
    } else {
        if (degrees < 0) degrees += 360;
        return degrees;
    }
}

void RoveEncoder::configInvert(bool invert) {
    m_inverted = invert;
}

void RoveEncoder::configOffset(float offsetDegrees) {
    m_offsetDegrees = offsetDegrees;
}

void RoveEncoder::configNegativeDegrees(bool enable) {
    m_allowNegativeDegrees = enable;
}

void RoveEncoder::setDegrees(float degrees) {
    configOffset(readDegrees() + m_offsetDegrees - degrees);
}

float RoveEncoder::readRadians() const {
    return readDegrees() * M_PI / 180.0;
}