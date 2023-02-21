#ifndef MA3PWM_H
#define MA3PWM_H

#include "RoveEncoder.h"

#include <cstdint>


class MA3PWM : public RoveEncoder {
// TODO add support for 10-bit resolution, 12-bit is currently the default

private:

    uint8_t m_pin;

    volatile uint32_t m_lastRisingEdge = 0;
    volatile uint32_t m_lastFallingEdge = 0;
    volatile uint16_t m_timeHigh = 1;
    volatile uint16_t m_timeLow = 4097;
    uint16_t m_lastTicks = 1;


public:

    /**
	 * @brief Construct a new MA3PWM object.
	 * 
	 * @param pin The Arduino pin number to use.
	 */
    MA3PWM(const uint8_t& pin) : m_pin(pin) {}


    /**
     * @brief Handle an edge change of the PWM signal
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
     * @brief Read the encoder value in PWM.
     * 
     * @return Current PWM value [0, 4096);
     */
    uint16_t readPWM();

    /**
	 * @brief Read the encoder value in degrees.
	 * 
	 * @return Current degree value [0, 360). 
	 */
    float readDegrees();
};

#endif