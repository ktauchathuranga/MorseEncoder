#include "MorseEncoder.h"

MorseEncoder morseA(9);       // Initialize with the desired pin for Audio **PWM pins only
MorseEncoder morseL(13);      // Initialize with the desired pin for Light

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM (word per minute) rate and frequency
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseA.print(message);   // [AUDIO] Boradcast encoded audio
  delay(2000);
  morseL.print(message);   // [LIGHT] Broadcast encoded light
  delay(2000);
}
