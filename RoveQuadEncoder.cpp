#include "RoveQuadEncoder.h"

#include <Arduino.h>

RoveQuadEncoder::RoveQuadEncoder(uint8_t pinA, uint8_t pinB, float cpr) {
    m_pinA = pinA;
    m_pinB = pinB;
    m_countsToDegrees = 360.0 / cpr;
}


/*
           _______         _______       
    ______|       |_______|       |______ A
       _______         _______         __
    __|       |_______|       |_______|   B

    negative <---             ---> positive


     last  current
	B	A	B	A	Movement
	------------------------
	0 | 0 | 0 | 0 |  0
	0 | 0 | 0 | 1 | +1
	0 | 0 | 1 | 0 | -1
	0 | 0 | 1 | 1 | +2
	0 | 1 | 0 | 0 | -1
	0 | 1 | 0 | 1 |  0
	0 | 1 | 1 | 0 | -2
	0 | 1 | 1 | 1 | +1
	1 | 0 | 0 | 0 | +1
	1 | 0 | 0 | 1 | -2
	1 | 0 | 1 | 0 |  0
	1 | 0 | 1 | 1 | -1
	1 | 1 | 0 | 0 | +2
	1 | 1 | 0 | 1 | -1
	1 | 1 | 1 | 0 | +1
	1 | 1 | 1 | 1 |  0

    * Movements of +/- 2 assume pin A edges, should mostly average out

*/
void RoveQuadEncoder::update() {
    uint8_t state = (m_lastB<<3) | (m_lastA<<2) | (m_currentB<<1) | (m_currentA<<0);
    
    switch (state) {
        case 1: case 7: case 8: case 14:
            m_count++;
            break;
        case 2: case 4: case 11: case 13:
            m_count--;
            break;
        case 3: case 12:
            m_count += 2;
            break;
        case 6: case 9:
            m_count -= 2;
            break;
    }
}

void RoveQuadEncoder::handleInterrupt() {
    m_lastA = m_currentA;
    m_lastB = m_currentB;
    m_currentA = digitalRead(m_pinA);
    m_currentB = digitalRead(m_pinB);

    update();
}

void RoveQuadEncoder::begin(void (*isr)(void)) {
    pinMode(m_pinA, INPUT);
    pinMode(m_pinB, INPUT);
    attachInterrupt(digitalPinToInterrupt(m_pinA), isr, CHANGE);
    attachInterrupt(digitalPinToInterrupt(m_pinB), isr, CHANGE);
}

float RoveQuadEncoder::readDegrees() const {
    return (m_inverted? -1 : 1) * m_count * m_countsToDegrees - m_offsetDegrees;
}