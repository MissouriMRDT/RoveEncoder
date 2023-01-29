#ifndef TESTENCODER_H
#define TESTENCODER_H

#include "RoveEncoder.h"


class TestEncoder : public RoveEncoder {

private:

	float m_degrees = 0;

public:

	/**
	 * @brief Construct a new TestEncoder object.
	 * 
	 */
	TestEncoder() {}
	
	/**
	 * @brief Set the value to be returned when read, before the offset is applied.
	 * 
	 * @param degrees 
	 */
	void setDegrees(const float& degrees);


	/**
	 * @brief Read the encoder value in degrees.
	 * 
	 * @return Current degree value.
	 */
	float readDegrees();

};

#endif