#ifndef ROVEENCODER_H
#define ROVEENCODER_H


class RoveEncoder {

protected:

    bool m_inverted = false;
    float m_offsetDegrees = 0;
    bool m_allowNegativeDegrees = false;

	/**
	 * @brief Bound the input degree value between 0 and 360.
	 * 
	 * @param degrees Value to be bounded.
	 * @return The equivalent angle [0, 360).
	 */
	float boundDegrees0_360(float degrees) const;

public:

    /**
     * @brief Configure whether to invert the encoder value when read.
     * 
     * @param invert 
     */
    void configInvert(const bool& invert);

    /**
     * @brief Configure the offset to subtract when read, after invert is applied.
     * Can be used to zero the encoder by calling configOffset(readDegrees()).
     * 
     * @param offsetDegrees 
     */
    void configOffset(const float& offsetDegrees);

    void configNegativeDegrees(const bool& enable);

    /**
     * @brief Calculate the offset that will make readDegrees() return the provided value.
     * 
     * @param degrees
     */
    void setDegrees(const float& degrees);


    /**
     * @brief Read the encoder value in radians.
     * 
     * @return Current radian value. 
     */
    float readRadians() const;

    /**
     * @brief Read the encoder value in degrees.
     * 
     * @return Current degree value. 
     */
    virtual float readDegrees() const = 0;
    
};

#endif