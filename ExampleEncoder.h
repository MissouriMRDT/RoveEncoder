#ifndef TESTENCODER_H
#define TESTENCODER_H

#include "RoveEncoder.h"

class ExampleEncoder : public RoveEncoder {

private:

	int m_port;
	float m_degrees = 0;

public:

	ExampleEncoder(int port) : m_port(port) {}
	
	void setDegrees(float degrees);

	float readDegrees();

};

#endif