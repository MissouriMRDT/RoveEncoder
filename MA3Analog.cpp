#include "MA3Analog.h"


void MA3Analog::configCalibration(float minAnalog, float maxAnalog, bool autoRecalibrate) {
	m_minAnalog = minAnalog;
	m_maxAnalog = maxAnalog;
	m_autoRecalibrate = autoRecalibrate;
}

float MA3Analog::analogToDegrees(float analog) const {
	if (analog < m_minAnalog) {
		if (m_autoRecalibrate) m_minAnalog = analog;
		else analog = m_minAnalog;
	}
	else if (analog > m_maxAnalog) {
		if (m_autoRecalibrate) m_maxAnalog = analog;
		else analog = m_maxAnalog;
	}

	return (analog - m_minAnalog) / (m_maxAnalog - m_minAnalog) * 360.0;
}


#if defined(ARDUINO)
#include <Arduino.h>


float MA3Analog::readDegrees() const {
	float degrees = (m_inverted? -1 : 1) * analogToDegrees(analogRead(m_pin)) - m_offsetDegrees;

	return boundDegrees0_360(degrees);
}


#endif