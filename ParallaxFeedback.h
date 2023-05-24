#ifndef PARALLAXFEEDBACK_H
#define PARALLAXFEEDBACK_H


#include "RoveEncoder.h"

#include <cstdint>


class ParallaxFeedback : public RoveEncoder {

private:

    uint8_t m_pin;
    mutable float m_minDutyCycle = 0.029, m_maxDutyCycle = 0.971;
    bool m_autoRecalibrate = false;
    
    volatile uint32_t m_lastRisingEdge = 0;
    volatile uint32_t m_lastFallingEdge = 0;
    volatile uint16_t m_timeHigh = 1;
    volatile uint16_t m_timeLow = 4097;
    volatile float m_lastDutyCycle = 0;
    mutable int64_t m_rotations = 0;

public:

    /**
	 * @brief Construct a new ParallaxFeedback object.
	 * 
	 * @param pin The Arduino pin number to use.
	 */
	ParallaxFeedback(const uint8_t& pin) : m_pin(pin) {}

    /**
     * @brief Set duty cycle bounds.
     * 
     * @param minDutyCycle The duty cycle corresponding to 0 degrees absolute rotation, defaults to 0.029 (2.9%).
     * @param maxDutyCycle The duty cycle corresponding to 359 degrees absolute rotation, defaults to 0.971 (97.1%).
     * @param autoRecalibrate Allow adjustment of minDutyCycle and maxDutyCycle if they are ever exceeded.
     */
    void configCalibration(const float& minDutyCycle, const float& maxDutyCycle, const bool& autoRecalibrate);
    
    /**
     * @brief Handle an edge change of the PWM signal.
     * 
     */
    void handleInterrupt();

    /**
     * @brief Attach interrupt to the provided Arduino pin.
     * 
     * @param isr The routine to call on edge change; pass a lambda expression to handleInterrupt().
     */
    void begin(void (*isr)(void));

    /**
     * @brief Read the encoder value in duty cycle.
     * 
     * @return Current duty cycle value [0, 1];
     */
    float readDutyCycle() const;

    /**
	 * @brief Read the encoder value in degrees.
	 * 
	 * @return Current degree value, unbounded. 
	 */
	float readDegrees() const;

};


#endif