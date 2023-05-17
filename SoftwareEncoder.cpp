#include "SoftwareEncoder.h"

void SoftwareEncoder::begin(float (*readDegrees)()) {
    m_readDegrees = readDegrees;
}

void SoftwareEncoder::configBoundDegrees(bool bound) {
    m_bound = bound;
}

float SoftwareEncoder::readDegrees() const {
    float degrees = (m_inverted? -1 : 1) * m_readDegrees() - m_offsetDegrees;

    return (m_bound? boundDegrees0_360(degrees) : degrees);
}