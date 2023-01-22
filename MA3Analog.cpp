#include "MA3Analog.h"

#include <cmath>


float MA3Analog::boundDegrees0_360(float degrees) {
	return fmod(fmod(degrees, 360.0) + 360.0, 360.0);
}

void MA3Analog::configCalibration(float minAnalog, float maxAnalog, bool autoRecalibrate) {
	m_minAnalog = minAnalog;
	m_maxAnalog = maxAnalog;
	m_autoRecalibrate = autoRecalibrate;
}

float MA3Analog::analogToDegrees(float analog) {
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


void MA3Analog::configFrequency(unsigned int frequency) {
	analogWriteFrequency(m_port, frequency);
}

float MA3Analog::readDegrees() {
	float degrees = (m_inverted? -1 : 1) * analogToDegrees(analogRead(m_port)) - m_offsetDegrees;

	return boundDegrees0_360(degrees);
}


#endif