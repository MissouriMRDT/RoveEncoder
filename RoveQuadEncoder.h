#ifndef QUADENCODER_H
#define QUADENCODER_H


#include "RoveEncoder.h"

#include <cstdint>


class RoveQuadEncoder : public RoveEncoder {

private:

    uint8_t m_pinA, m_pinB;
    mutable int64_t m_count;
    float m_countsToDegrees;

    bool m_currentA = false, m_currentB = false;
    bool m_lastA = false, m_lastB = false;

    /**
     * @brief Update count based on the values of pinA and pinB.
     * 
     */
    void update();

public:

    /**
     * @brief Construct a new RoveQuadEncoder object.
     * 
     * @param pinA Arduino pin number.
     * @param pinB Arduino pin number.
     * @param cpr Encoder counts per rotation of output shaft.
     */
    RoveQuadEncoder(uint8_t pinA, uint8_t pinB, float cpr);

    /**
     * @brief Handle an edge change in the pinA or pinB signal.
     * 
     */
    void handleInterrupt();

    /**
     * @brief Attach interrupt to the provided arduino pins.
     * 
     * @param isr Function to call on pinA or pinB edge change; pass a lambda expression to handleInterrupt().
     */
    void begin(void (*isr)(void));

    /**
     * @brief Read the encoder value in degrees.
     * 
     * @return Current degree value, unbounded.
     */
    float readDegrees() const;

};


#endif