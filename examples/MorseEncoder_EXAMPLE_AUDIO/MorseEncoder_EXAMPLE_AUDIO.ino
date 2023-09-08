#include "MorseEncoder.h"

MorseEncoder morseA(9);  // Initialize with the desired pin for Audio

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM rate and frequency, defult wpm = 15 and frequency = 600
}

void loop() {
  String message = "sos";
  morseA.encodeAudio(message); // [AUDIO] Boradcast encoded audio
  delay(2000);
}