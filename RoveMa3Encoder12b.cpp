#include <stdint.h>
#include "RoveMa3Encoder12b.h"
#include "RovePwmRead.h"

Ma3Encoder12b::Ma3Encoder12b(const int pwmPin): offset(0), pwmMax(PWM_READ_MAX), reversed(false)
{
  RovePwmRead encoderPin = RovePwmRead(pwmPin);
  encoderPin.start();

}

long Ma3Encoder12b::getPosition()
{
  int32_t width;

  width = encoderPin.readWidth();

  if(reversed)
  {
    width = pwmMax - width + PWM_READ_MIN;
  }

  long absoluteAngle = map(width, PWM_READ_MIN, pwmMax, POS_MIN, POS_MAX);

  long angle = absoluteAngle+offset;

  if(angle > (long)POS_MAX)
  {
    angle -= (POS_MAX-POS_MIN);
  }
  else if(angle < (long)POS_MIN)
  {
    angle += (POS_MAX-POS_MIN);
  }

  return(angle);
}

float Ma3Encoder12b::getDegrees()
{
  long position = getPosition();
  return (position * 360.0 / ((float)(POS_MAX - POS_MIN)));
}

void Ma3Encoder12b::setOffset(uint16_t offsetAngle)
{
  if( offset < 0 )
  {
    offset = -map( offsetAngle, 0, 360, POS_MIN, POS_MAX );
  }
  else if( offset >= 0 )
  {
    offset =  map( offsetAngle, 0, 360, POS_MIN, POS_MAX );
  }
}

void Ma3Encoder12b::setMaxPwm(uint32_t maxPwm)
{
  pwmMax = maxPwm;
}

void Ma3Encoder12b::reverseDirection(bool reverse)
{
  reversed = reverse;
}
