#include <MA3PWM.h>

// Encoder Pins
const uint8_t ENC_1 = 33;
const uint8_t ENC_2 = 13;
const uint8_t ENC_3 = 12;
const uint8_t ENC_4 = 25;
const uint8_t ENC_5 = 28;
const uint8_t ENC_6 = 29;

// Encoders
MA3PWM encoder1(ENC_1);
MA3PWM encoder2(ENC_2);
MA3PWM encoder3(ENC_3);
MA3PWM encoder4(ENC_4);
MA3PWM encoder5(ENC_5);
MA3PWM encoder6(ENC_6);

void setup() {
  Serial.begin(115200);

  // The isr must be a static method to satisfy Arduino's attachInterrupt() method.
  // This is achieved by creating a static lambda expression to the nonstatic handleInterrupt().
  encoder1.begin( []{encoder1.handleInterrupt();} );
  encoder2.begin( []{encoder2.handleInterrupt();} );
  encoder3.begin( []{encoder3.handleInterrupt();} );
  encoder4.begin( []{encoder4.handleInterrupt();} );
  encoder5.begin( []{encoder5.handleInterrupt();} );
  encoder6.begin( []{encoder6.handleInterrupt();} );
}

void loop() {
  Serial.print(encoder1.readPWM());
  Serial.print(", ");
  Serial.print(encoder2.readPWM());
  Serial.print(", ");
  Serial.print(encoder3.readPWM());
  Serial.print(", ");
  Serial.print(encoder4.readPWM());
  Serial.print(", ");
  Serial.print(encoder5.readPWM());
  Serial.print(", ");
  Serial.println(encoder6.readPWM());
  delay(100);
}
