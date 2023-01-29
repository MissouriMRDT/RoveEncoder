#include "TestEncoder.h"


void TestEncoder::setDegrees(const float& degrees) {
    m_degrees = degrees;
}

float TestEncoder::readDegrees() {
    return (m_inverted? -1 : 1) * m_degrees - m_offsetDegrees;
}