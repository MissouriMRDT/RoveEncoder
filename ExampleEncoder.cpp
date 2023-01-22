#include "ExampleEncoder.h"


void ExampleEncoder::setDegrees(float degrees) {
    m_degrees = degrees;
}

float ExampleEncoder::readDegrees() {
    return (m_inverted? -1 : 1) * m_degrees - m_offsetDegrees;
}