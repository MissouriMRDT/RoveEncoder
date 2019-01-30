/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MRDT 2019 => TivaC1294/TivaC129E Pin Module Pulse Width Modulation Capture (PWM CCP)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RoveUsDigiMa3Pwm.h"

//////////////////////////////////////////////////////////////////////////////
RoveUsDigiMa3Pwm    Encoder_TimerT4APinPM4; // or TimerT4APinPB0 or TimerT4APinPD6

//////////////////
void debugPrint();

///////////////////////////////////////////////////////////////////////////////
void setup() 
{
  ////////////////////////////////////
  Serial.begin(9600);
  pinMode(PF_0, OUTPUT); // Todo debug

  /////////////////////////////////////////////////////////////////////////////
  Encoder_TimerT4APinPM4.attach( PM_4 ); // or attach( PB_0 ) or attach( PD_6 )
  Encoder_TimerT4APinPM4.start();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void debugPrint()
{
  Serial.print(  "Encoder_TimerT4APinPM4 angle degrees: "); Serial.println( Encoder_TimerT4APinPM4.readMillidegrees() / 1000.0 ); 
  Serial.print(  "Encoder_TimerT4APinPM4 angle radians: "); Serial.println( Encoder_TimerT4APinPM4.readRadians()               ); 
}

//////////////////////////////////////////////////////
void loop() 
{
  ////////////////////////////// 
//Encoder_TimerT4APinPM4.stop(); 

  debugPrint();
  delay(500); 

  ///////////////////////////////
//Encoder_TimerT4APinPM4.start();
}






/*
////////////////////////////////////////////////////////////////////////////////
UsDigiMa3Pwm    Encoder_TimerT0APinPD0; // or TimerT0APinPA0 or TimerT0APinPL4
UsDigiMa3Pwm    Encoder_TimerT0BPinPD1; // or TimerT0BPinPA1 or TimerT0BPinPL5
UsDigiMa3Pwm    Encoder_TimerT1APinPD2; // or TimerT1APinPA2 or TimerT1APinPL6
UsDigiMa3Pwm    Encoder_TimerT1BPinPD3; // or TimerT1BPinPA3 or TimerT1BPinPL7
UsDigiMa3Pwm    Encoder_TimerT2APinPA4; // or TimerT2APinPM0    
UsDigiMa3Pwm    Encoder_TimerT2BPinPA5; // or TimerT2BPinPM1    
UsDigiMa3Pwm    Encoder_TimerT3APinPA6; // or TimerT3APinPM2 or TimerT3APinPD4
UsDigiMa3Pwm    Encoder_TimerT3BPinPA7; // or TimerT3BPinPM3 or TimerT3BPinPD5
UsDigiMa3Pwm    Encoder_TimerT4APinPM4; // or TimerT4APinPB0 or TimerT4APinPD6
UsDigiMa3Pwm    Encoder_TimerT4BPinPM5; // or TimerT4BPinPB1 or TimerT4BPinPD7
UsDigiMa3Pwm    Encoder_TimerT5APinPM6; // or TimerT5APinPB2
UsDigiMa3Pwm    Encoder_TimerT5BPinPM7; // or TimerT5BPinPB3

///////////////////////////////////////////////////////////////
RovePwmReadWireBreaks     AllEncodersPinWirebreaks_Timer6A;

//////////////////
void debugPrint();

///////////////////////////////////////////////////////////////////////////////
void setup() 
{
  ////////////////////////////////////
  Serial.begin(9600);
  pinMode(PF_0, OUTPUT); // Todo debug

  /////////////////////////////////////////////////////////////////////////////
  Encoder_TimerT0APinPD0.attach( PD_0 ); // or attach( PA_0 ) or attach( PL_4 )
  Encoder_TimerT0BPinPD1.attach( PD_1 ); // or attach( PA_1 ) or attach( PL_5 )
  Encoder_TimerT1APinPD2.attach( PD_2 ); // or attach( PA_2 ) or attach( PL_6 )
  Encoder_TimerT1BPinPD3.attach( PD_3 ); // or attach( PA_3 ) or attach( PL_7 )
  Encoder_TimerT2APinPA4.attach( PA_4 ); // or attach( PM_0 )                 
  Encoder_TimerT2BPinPA5.attach( PA_5 ); // or attach( PM_1 )                 
  Encoder_TimerT3APinPA6.attach( PA_6 ); // or attach( PM_2 ) or attach( PD_4 )
  Encoder_TimerT3BPinPA7.attach( PA_7 ); // or attach( PM_3 ) or attach( PD_5 )
  Encoder_TimerT4APinPM4.attach( PM_4 ); // or attach( PB_0 ) or attach( PD_6 )
  Encoder_TimerT4BPinPM5.attach( PM_5 ); // or attach( PB_1 ) or attach( PD_7 )
  Encoder_TimerT5APinPM6.attach( PM_6 ); // or attach( PB_2 )
  Encoder_TimerT5BPinPM7.attach( PM_7 ); // or attach( PB_3 )

  AllEncodersPinWirebreaks_Timer6A.attachMicros( T6_A, 10 );
  AllEncodersPinWirebreaks_Timer6A.start();

  Encoder_TimerT0APinPD0.start();
  Encoder_TimerT0BPinPD1.start();
  Encoder_TimerT1APinPD2.start();
  Encoder_TimerT1BPinPD3.start();
  Encoder_TimerT2APinPA4.start();
  Encoder_TimerT2BPinPA5.start();
  Encoder_TimerT3APinPA6.start();
  Encoder_TimerT3BPinPA7.start();
  Encoder_TimerT4APinPM4.start();
  Encoder_TimerT4BPinPM5.start();
  Encoder_TimerT5APinPM6.start();
  Encoder_TimerT5BPinPM7.start();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
void debugPrint()
{
  Serial.print( "EncoderPD0_TimerT0A angle degrees: "); Serial.print(   EncoderPD0_TimerT0A.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPD0_TimerT0A.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPD0_TimerT0A.isWireBroken());
                                                                        
  Serial.print( "EncoderPD1_TimerT0B angle degrees: "); Serial.print(   EncoderPD1_TimerT0B.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPD1_TimerT0B.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPD1_TimerT0B.isWireBroken());
                                                                        
  Serial.print( "EncoderPD2_TimerT1A angle degrees: "); Serial.print(   EncoderPD2_TimerT1A.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPD2_TimerT1A.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPD2_TimerT1A.isWireBroken());
                                                                        
  Serial.print( "EncoderPD3_TimerT1B angle degrees: "); Serial.print(   EncoderPD3_TimerT1B.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPD3_TimerT1B.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPD3_TimerT1B.isWireBroken());
                                                                        
  Serial.print( "EncoderPA4_TimerT2A angle degrees: "); Serial.print(   EncoderPA4_TimerT2A.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPA4_TimerT2A.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPA4_TimerT2A.isWireBroken());
                                                                        
  Serial.print( "EncoderPA5_TimerT2B angle degrees: "); Serial.print(   EncoderPA5_TimerT2B.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPA5_TimerT2B.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPA5_TimerT2B.isWireBroken());
                                                                        
  Serial.print( "EncoderPA6_TimerT3A angle degrees: "); Serial.print(   EncoderPA6_TimerT3A.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPA6_TimerT3A.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPA6_TimerT3A.isWireBroken());
                                                                        
  Serial.print( "EncoderPA7_TimerT3B angle degrees: "); Serial.print(   EncoderPA7_TimerT3B.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPA7_TimerT3B.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPA7_TimerT3B.isWireBroken());
                                                                        
  Serial.print( "EncoderPM4_TimerT4A angle degrees: "); Serial.print(   EncoderPM4_TimerT4A.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPM4_TimerT4A.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPM4_TimerT4A.isWireBroken());
                                                                        
  Serial.print( "EncoderPM5_TimerT4B angle degrees: "); Serial.print(   EncoderPM5_TimerT4B.readMillidegrees()); 
  Serial.print( ", angle  radians: ");                  Serial.print(   EncoderPM5_TimerT4B.readRadians());
  Serial.print( ", wirebreak: ");                       Serial.println( EncoderPM5_TimerT4B.isWireBroken());
}

//////////////////////////////////////////////////////
void loop() 
{
  Serial.println("RovePwmRead all"); Serial.println();

  //////////////////////////////
  Encoder_TimerT0APinPD0.stop(); 
  Encoder_TimerT0BPinPD1.stop(); 
  Encoder_TimerT1APinPD2.stop(); 
  Encoder_TimerT1BPinPD3.stop(); 
  Encoder_TimerT2APinPA4.stop(); 
  Encoder_TimerT2BPinPA5.stop(); 
  Encoder_TimerT3APinPA6.stop(); 
  Encoder_TimerT3BPinPA7.stop(); 
  Encoder_TimerT4APinPM4.stop(); 
  Encoder_TimerT4BPinPM5.stop(); 
  Encoder_TimerT5APinPM6.stop(); 
  Encoder_TimerT5BPinPM7.stop(); 

  debugPrint();
  delay(2000); 

  debugPrint();
  delay(2000);

  ///////////////////////////////
  Encoder_TimerT0APinPD0.start(); 
  Encoder_TimerT0BPinPD1.start(); 
  Encoder_TimerT1APinPD2.start(); 
  Encoder_TimerT1BPinPD3.start(); 
  Encoder_TimerT2APinPA4.start(); 
  Encoder_TimerT2BPinPA5.start(); 
  Encoder_TimerT3APinPA6.start(); 
  Encoder_TimerT3BPinPA7.start(); 
  Encoder_TimerT4APinPM4.start(); 
  Encoder_TimerT4BPinPM5.start(); 
  Encoder_TimerT5APinPM6.start(); 
  Encoder_TimerT5BPinPM7.start(); 

  debugPrint();
  delay(2000); 

  debugPrint();
  delay(2000);
}
*/
