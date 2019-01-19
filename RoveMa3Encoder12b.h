#ifndef MA3ENCODER12B_H_
#define MA3ENCODER12B_H_

#include <stdint.h>


class RoveMa3Encoder
{
  private:

    long offset;
    uint32_t pwmMax;
    bool reversed;

    const uint32_t POS_MIN = 0
    const uint32_t POS_MAX = 360000
    const uint16_t PWM_READ_MIN = 1
    const uint16_t PWM_READ_MAX = 4095


  public:


    //pwmPin: Pin mapping of the pin to read PWM signals off of.
    Ma3Encoder12b(uint16_t pwmPin);

    //get the position from the encoder, returns values between POS_MIN, POS_MAX
    long getPosition();

    //set an offset for the Ma3Encoder12b
    //takes degrees
    //FUTURE: store the encoder positions across reboots?
    void setOffset(float offset);

    //get the position, returned in degrees between 0-360
    float getDegrees();

    //calibration value that we can tweak and tune
    //default is PWM_READ_MAX
    void setMaxPwm(uint32_t maxPwm);

    //reversing our encoder values if mounted differently
    void reverseDirection(bool reverse);

};

#endif
