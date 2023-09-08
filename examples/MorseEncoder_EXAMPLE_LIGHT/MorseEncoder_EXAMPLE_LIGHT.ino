#include "MorseEncoder.h"

MorseEncoder morseL(13); // Initialize with the desired pin for Light

void setup() {
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseL.encodeLight(message); // [LIGHT] Broadcast encoded light
  delay(2000);
}
