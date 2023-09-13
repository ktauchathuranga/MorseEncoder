#include "MorseEncoder.h"

MorseEncoder morseA(9);  // Initialize with the desired pin for Audio **PWM pins only

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM (word per minute rate) rate and frequency
}

void loop() {
  String message = "sos";
  morseA.print(message); // [AUDIO] Boradcast encoded audio >> or you can use morseA.encodeAudio(message); **for the strings only
  delay(2000);
  morseA.print(123);     // [AUDIO] its inherits from Print class, so you can encode various types of data
  delay(2000);
}
