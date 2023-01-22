#include "RoveEncoder.h"

#define _USE_MATH_DEFINES
#include <cmath>


void RoveEncoder::configInvert(bool invert) {
    m_inverted = invert;
}

void RoveEncoder::configOffset(float offsetDegrees) {
    m_offsetDegrees = offsetDegrees;
}

float RoveEncoder::readRadians() {
    return readDegrees() * M_PI / 180.0;
}