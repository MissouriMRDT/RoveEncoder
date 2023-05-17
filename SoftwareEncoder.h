#ifndef SOFTWAREENCODER_H
#define SOFTWAREENCODER_H

#include "RoveEncoder.h"


class SoftwareEncoder : public RoveEncoder {

private:

    float (*m_readDegrees)(void) = nullptr;
    bool m_bound = false;

public:

	/**
	 * @brief Construct a new SoftwareEncoder object.
	 * 
	 */
	SoftwareEncoder() {}

    /**
     * @brief Configure the function of readDegrees.
     * 
     * @param readDegrees Pointer to a function call, must return current degree value of encoder.
     */
    void begin(float (*readDegrees)(void));

    /**
     * @brief Select whether or not to bound the output of read degrees.
     * 
     * @param bound True to bound 0 to 360 degrees, false otherwise.
     */
    void configBoundDegrees(bool bound);

	/**
	 * @brief Read the encoder value in degrees.
	 * 
	 * @return Current degree value.
	 */
	float readDegrees() const;

};

#endif