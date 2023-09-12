#include "Arduino.h"
#include "MorseEncoder.h"

MorseEncoder::MorseEncoder(int pin) {
  _pin = pin;
}

void MorseEncoder::beginAudio(int wpm, int freq) {   // removed int wpm = 15, int freq = 600 def values cuz esp8266 gimme hard times
  _unitTime = 1200 / wpm;
  _freq = freq;

  pinMode(_pin, OUTPUT);
  //Serial.begin(9600);
}

void MorseEncoder::beginLight(int wpm) {
  _unitTime = 1200 / wpm;

  pinMode(_pin, OUTPUT);
  //Serial.begin(9600);
}

void MorseEncoder::encodeAudio(String text) {
  MorseEncoder::encode(text, 1);
}

void MorseEncoder::encodeLight(String text) {
  MorseEncoder::encode(text, 0);
}

void MorseEncoder::encode(String text, int mode) {
  text.toUpperCase();
  for (int i = 0; i < text.length(); i++) {
    char character = text.charAt(i);
    //char character = 'O'; // Replace with the letter you want to print
    int index = character - 'A'; // Calculate the index for the letter

    if (index >= 0 && index < 26) {
      const char* morse = reinterpret_cast<const char*>(pgm_read_word(&morseCodes[index])); // Get the Morse code for the letter

      for (int j = 0; morse[j] != '\0'; j++) {
        if (morse[j] == '.') {
          dot(mode);
        } else if (morse[j] == '-') {
          dash(mode);
        }
        //Serial.print(morse[j]); // Print each individual character of Morse code
      }

      //Serial.println(); // Print a new line to separate Morse codes
      letterSpace();
    } else if (character >= '0' && character <= '9') {
      // Handle numbers if needed
      int index = character - '0' + 26; // Calculate the index for the digit

      const char* morse = reinterpret_cast<const char*>(pgm_read_word(&morseCodes[index])); // Get the Morse code for the digit

      for (int j = 0; morse[j] != '\0'; j++) {
        if (morse[j] == '.') {
          dot(mode);
        } else if (morse[j] == '-') {
          dash(mode);
        }
        //Serial.print(morse[j]);
      }
      //Serial.println();
      letterSpace();
    } else if (character == ' ') {
      // Handle space if needed
      space();
    } else {
      // Handle other characters or invalid characters as needed
      int index = -1;

      // Check if the character is one of the special characters
      const char specialChars[] = ".,:;?=/!-_\"()$@&+";
      for (int j = 0; j < sizeof(specialChars) - 1; j++) {
        if (character == specialChars[j]) {
          index = j;
          break;
        }
      }

      if (index >= 0 && index < 17) {
        const char* morse = reinterpret_cast<const char*>(pgm_read_word(&morseSpecialChars[index])); // Get the Morse code for the character

        for (int j = 0; morse[j] != '\0'; j++) {
          if (morse[j] == '.') {
            dot(mode);
          } else if (morse[j] == '-') {
            dash(mode);
          }
          //Serial.print(morse[j]);
        }
        //Serial.println();
        letterSpace();
      }
    }
  }
}
