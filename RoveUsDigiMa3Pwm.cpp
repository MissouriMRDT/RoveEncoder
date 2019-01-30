////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT 2019 => Energia Texas Instruments Tiva C Todo...
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RoveUsDigiMa3Pwm.h"
#include "RoveTimerInterrupt.h"
#include "RovePwmRead.h"

#include "Energia.h"

#include <stdint.h>

//////////////////////////////////////////////////////////////////////////
void      RoveUsDigiMa3Pwm::attach( const uint8_t pin, const int priority )
{ this->EncoderCcpTimer.attach(               pin,           priority ); }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int RoveUsDigiMa3Pwm::readMillidegrees()
{ 
  int width_min_decipercent = 330; // todo => debug, then constants
  int width_max_decipercent = 660; // todo => debug, then constants
  int width_decipercent = this->EncoderCcpTimer.readDutyDecipercent();

  if(      width_decipercent < width_min_decipercent  ) { width_decipercent = width_min_decipercent; }
  else if( width_decipercent > width_max_decipercent  ) { width_decipercent = width_max_decipercent; }

  return map( width_decipercent, width_min_decipercent, width_max_decipercent, 0, 360000 ); 
}

//////////////////////////////////////////////////////////////////////////
float RoveUsDigiMa3Pwm::readRadians()
{ return DEG_TO_RAD * ( this->readMillidegrees() / 1000.0 );  } // Todo

//////////////////////////////////////////////////////////////////////////////////
void RoveUsDigiMa3Pwm::start()        {        this->EncoderCcpTimer.start(); }
void RoveUsDigiMa3Pwm::stop()         {        this->EncoderCcpTimer.stop(); }
bool RoveUsDigiMa3Pwm::isWireBroken() { return this->EncoderCcpTimer.isWireBroken(); }

/////////////////////////////////////////////////////////////////////////////////////////////
void RoveUsDigiMa3PwmWireBreaks::attachMillis( uint8_t timer, int period_millis, int priority )
{   this->AllWireBreaksTimer.attachMillis(         timer,     period_millis,     priority ); }

///////////////////////////////////////////////////////////////////////////////////////////////
void RoveUsDigiMa3PwmWireBreaks::attachMicros( uint8_t timer, int period_micros, int priority )
{   this->AllWireBreaksTimer.attachMicros(         timer,     period_micros,     priority ); }

//////////////////////////////////////////////////////////////////////////
void RoveUsDigiMa3PwmWireBreaks::start() { this->AllWireBreaksTimer.start(); }
void RoveUsDigiMa3PwmWireBreaks::stop()  { this->AllWireBreaksTimer.stop();  }