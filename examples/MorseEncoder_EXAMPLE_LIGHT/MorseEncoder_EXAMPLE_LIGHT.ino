#include "MorseEncoder.h"

MorseEncoder morseL(13);      // Initialize with the desired pin for Light

void setup() {
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseL.print(message);   // [LIGHT] Broadcast encoded light
  delay(2000);
  morseL.print(123);       // [LIGHT] its inherits from Print class, so you can encode various types of data
  delay(2000);
}
