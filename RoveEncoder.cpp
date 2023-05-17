#include "RoveEncoder.h"

#define _USE_MATH_DEFINES
#include <cmath>


float RoveEncoder::boundDegrees0_360(float degrees) const {
	degrees = fmod(degrees, 360.0);
	return (degrees < 0)? (degrees + 360.0) : degrees;
}

void RoveEncoder::configInvert(const bool& invert) {
    m_inverted = invert;
}

void RoveEncoder::configOffset(const float& offsetDegrees) {
    m_offsetDegrees = offsetDegrees;
}

void RoveEncoder::setDegrees(const float& degrees) {
    configOffset(readDegrees() + m_offsetDegrees - degrees);
}

float RoveEncoder::readRadians() const {
    return readDegrees() * M_PI / 180.0;
}