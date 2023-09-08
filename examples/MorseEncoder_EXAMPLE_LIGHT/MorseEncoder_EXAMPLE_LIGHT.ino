#include "MorseEncoder.h"

MorseEncoder morseL(13); // Initialize with the desired pin for Light

void setup() {
  morseL.beginLight(15);      // [LIGHT] Initialize WPM rate and frequency, defult wpm = 15
}

void loop() {
  String message = "sos";
  morseL.encodeLight(message); // [LIGHT] Broadcast encoded light
  delay(2000);
}