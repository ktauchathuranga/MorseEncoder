#include "MorseEncoder.h"

MorseEncoder morseA(9);  // Initialize with the desired pin for Audio
MorseEncoder morseL(13); // Initialize with the desired pin for Light

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM (word per minute) rate and frequency
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseA.encodeAudio(message); // [AUDIO] Boradcast encoded audio
  delay(2000);
  morseL.encodeLight(message); // [LIGHT] Broadcast encoded light
  delay(2000);
}
