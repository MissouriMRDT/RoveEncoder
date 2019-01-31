///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT 2019 => Energia Texas Instruments Tiva C, US Digital Encoder, Pwm 12b Ma3
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROVE_US_DIGI_MA3_PWM_H
#define ROVE_US_DIGI_MA3_PWM_H

#include "RovePwmRead.h"

#include <stdint.h>

////////////////////////////////////////////////////
class RoveUsDigiMa3Pwm
{
public:
  void  attach( uint8_t pin, int priority=7 );
  void  start();
  void  stop();

  int   readMillidegrees();
  float readRadians();

  bool  isWireBroken();

//private:
  
  RovePwmRead    EncoderCcpTimer;
  uint8_t        pin;
};

///////////////////////////////////////////////////////////////////////
class RoveUsDigiMa3PwmWireBreaks
{
  public: 
  void attachMillis( uint8_t timer, int period_millis, int priority=7 );
  void attachMicros( uint8_t timer, int period_micros, int priority=7 );

  void start();
  void stop();
//private:

  RovePwmReadWireBreaks    AllWireBreaksTimer;
};

#endif // ROVE_US_DIGI_MA3_PWM_H