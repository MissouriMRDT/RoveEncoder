#include "ParallaxFeedback.h"

void ParallaxFeedback::configCalibration(float minDutyCycle, float maxDutyCycle, bool autoRecalibrate) {
    m_minDutyCycle = minDutyCycle;
    m_maxDutyCycle = maxDutyCycle;
    m_autoRecalibrate = autoRecalibrate;
}


#if defined(ARDUINO)
#include <Arduino.h>


void ParallaxFeedback::handleInterrupt() {
    if (digitalRead(m_pin)) {
        m_timeHigh = m_lastFallingEdge - m_lastRisingEdge;
        m_lastRisingEdge = micros();
        m_timeLow = m_lastRisingEdge - m_lastFallingEdge;

        float dutyCycle = (float) m_timeHigh / (m_timeLow + m_timeHigh);
        if (dutyCycle > m_maxDutyCycle) {
            if (m_autoRecalibrate) m_maxDutyCycle = dutyCycle;
            else dutyCycle = m_maxDutyCycle;
        }
        else if (dutyCycle < m_minDutyCycle) {
            if (m_autoRecalibrate) m_minDutyCycle = dutyCycle;
            else dutyCycle = m_minDutyCycle;
        }

        float q1_max = (m_maxDutyCycle - m_minDutyCycle) / 4.0;
        float q4_min = q1_max * 3.0;
        if ((dutyCycle <= q1_max) && (m_lastDutyCycle >= q4_min)) {
            m_rotations++; // 4th quadrant to 1st quadrant
        }
        else if ((dutyCycle >= q4_min) && (m_lastDutyCycle <= q1_max)) {
            m_rotations--; // 1st quadrant to 4th quadrant
        }

        m_lastDutyCycle = dutyCycle;
    }
    else {
        m_lastFallingEdge = micros();
    }
}

void ParallaxFeedback::begin(void (*isr)(void)) {
    pinMode(m_pin, INPUT);
    attachInterrupt(digitalPinToInterrupt(m_pin), isr, CHANGE);
}


#endif

float ParallaxFeedback::readDutyCycle() const {
    return m_lastDutyCycle;
}

float ParallaxFeedback::readDegrees() const {
    float rotations = ((float) m_rotations) + ((m_lastDutyCycle - m_minDutyCycle) / (m_maxDutyCycle - m_minDutyCycle));
    return (m_inverted? -1 : 1) * rotations * 360.0 - m_offsetDegrees;
}