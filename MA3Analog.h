#ifndef MA3ANALOG_H
#define MA3ANALOG_H

#include "RoveEncoder.h"

class MA3Analog : public RoveEncoder {

private:

	int m_port;
	float m_minAnalog = 0, m_maxAnalog = 1023;
	bool m_autoRecalibrate = false;

	float boundDegrees0_360(float degrees);
	float analogToDegrees(float analog);

public:

	MA3Analog(int port) : m_port(port) {}

	void configCalibration(float minAnalog, float maxAnalog, bool autoRecalibrate);
	void configFrequency(unsigned int frequency);

	float readDegrees();
	
};

#endif