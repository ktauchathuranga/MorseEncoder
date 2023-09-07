#include "MorseEncoder.h"

MorseEncoder morse(9); // Initialize with the desired pin

void setup() {
  morse.begin(15, 500); // Initialize WPM rate and frequency, defult wpm = 15 and frequency = 600
}

void loop() {
  String message = "sos";
  morse.encode(message);
  delay(1000);
}
