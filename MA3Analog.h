#ifndef MA3ANALOG_H
#define MA3ANALOG_H

#include "RoveEncoder.h"

#include <cstdint>


class MA3Analog : public RoveEncoder {

private:

	uint8_t m_pin;
	mutable float m_minAnalog = 0, m_maxAnalog = 1023;
	bool m_autoRecalibrate = false;

	/**
	 * @brief Convert the input analog value to degrees.
	 * 
	 * @param analog Value to convert.
	 * @return Equivalent reading in degrees.
	 */
	float analogToDegrees(float analog) const;

public:

	/**
	 * @brief Construct a new MA3Analog object.
	 * 
	 * @param pin The Arduino pin number to use.
	 */
	MA3Analog(uint8_t pin) : m_pin(pin) {}

	/**
	 * @brief Configure the values used to convert Arduino analogRead() to degrees.
	 * 
	 * @param minAnalog The minimum analog signal, defaults to 0.
	 * @param maxAnalog The maximum analog signal, defaults to 1023.
	 * @param autoRecalibrate Allow adjustment of minAnalog and maxAnalog if they are ever exceeded.
	 */
	void configCalibration(float minAnalog, float maxAnalog, bool autoRecalibrate);

	/**
	 * @brief Read the encoder value in degrees.
	 * 
	 * @return Current degree value [0, 360). 
	 */
	float readDegrees() const;
	
};

#endif