#include "MA3PWM.h"


#if defined(ARDUINO)
#include <Arduino.h>


void MA3PWM::handleInterrupt() {
    if (digitalRead(m_pin)) {
        m_timeHigh = m_lastFallingEdge - m_lastRisingEdge;
        m_lastRisingEdge = micros();
        m_timeLow = m_lastRisingEdge - m_lastFallingEdge; 
    }
    else {
        m_lastFallingEdge = micros();
    }
}

void MA3PWM::begin(void (*isr)(void)) {
    pinMode(m_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(m_pin), isr, CHANGE);
}


#endif


uint16_t MA3PWM::readPWM() const {
    // See https://www.usdigital.com/products/encoders/absolute/shaft/ma3/ for details
    uint16_t ticks = (m_timeHigh * 4098) / (m_timeHigh + m_timeLow);
    
    if (ticks > 4097) ticks = m_lastTicks;
    else m_lastTicks = ticks;

    return (ticks == 4097)? 4095 : ticks - 1;
}

float MA3PWM::readDegrees() const {
	float degrees = ((m_inverted? -1 : 1) * readPWM() * 360.0 / 4096.0) - m_offsetDegrees;
    degrees = boundDegrees0_360(degrees);

    if (m_allowNegativeDegrees) {
        if (degrees > 180) degrees -= 360;
    }
    
	return degrees;
}