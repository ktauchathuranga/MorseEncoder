#include "Arduino.h"
#include "MorseEncoder.h"

MorseEncoder::MorseEncoder(int pin) {
  _pin = pin;
}

void MorseEncoder::beginAudio(int wpm, int freq) {   // removed int wpm = 15, int freq = 600 def values cuz esp8266 gimme hard times
  _unitTime = 1200 / wpm;
  _freq = freq;
  _mode = 1;

  pinMode(_pin, OUTPUT);
  //Serial.begin(9600);
}

void MorseEncoder::beginLight(int wpm) {
  _unitTime = 1200 / wpm;
  _mode = 0;

  pinMode(_pin, OUTPUT);
  //Serial.begin(9600);
}

//----------- old method strt -----------

// void MorseEncoder::encodeAudio(String text) {
//   MorseEncoder::encode(text);
//   _mode = 1;
// }

// void MorseEncoder::encodeLight(String text) {
//   MorseEncoder::encode(text);
//   _mode = 0;
// }

//----------- old method end -----------

unsigned int MorseEncoder::write(uint8_t character) {
  //Serial.println(character);
  character = toupper(character);
  int index = character - 'A'; // Calculate the index for the letter

  if (index >= 0 && index < 26) {
    const char* morse = reinterpret_cast<const char*>(pgm_read_dword(&morseCodes[index])); // Get the Morse code for the letter

    for (int j = 0; morse[j] != '\0'; j++) {
      if (morse[j] == '.') {
        dot(_mode);
      } else if (morse[j] == '-') {
        dash(_mode);
      }
      //Serial.println(morse[j]); // Print each individual character of Morse code
    }

    //Serial.println(); // Print a new line to separate Morse codes
    letterSpace();
    return 1;
  } else if (character >= '0' && character <= '9') {
    // Handle numbers if needed
    int index = character - '0' + 26; // Calculate the index for the digit

    const char* morse = reinterpret_cast<const char*>(pgm_read_dword(&morseCodes[index])); // Get the Morse code for the digit

    for (int j = 0; morse[j] != '\0'; j++) {
      if (morse[j] == '.') {
        dot(_mode);
      } else if (morse[j] == '-') {
        dash(_mode);
      }
      //Serial.print(morse[j]);
    }
    //Serial.println();
    letterSpace();
    return 1;
  } else if (character == ' ') {
    // Handle space if needed
    space();
    return 1;
  } else {
    // Handle other characters or invalid characters as needed
    int index = -1;

    // Check if the character is one of the special characters
    const char specialChars[] = ".,:;?=/!-_\"()$@&+";
    for (unsigned int j = 0; j < sizeof(specialChars) - 1; j++) {
      if (character == specialChars[j]) {
        index = j;
        break;
      }
    }

    if (index >= 0 && index < 17) {
      const char* morse = reinterpret_cast<const char*>(pgm_read_dword(&morseSpecialChars[index])); // Get the Morse code for the character

      for (int j = 0; morse[j] != '\0'; j++) {
        if (morse[j] == '.') {
          dot(_mode);
        } else if (morse[j] == '-') {
          dash(_mode);
        }
        //Serial.print(morse[j]);
      }
      //Serial.println();
      letterSpace();
      return 1;
    }
  }

  return 0;

}

//----------- old method strt -----------

// void MorseEncoder::encode(String text) {
//   //text.toUpperCase(); // its converting inside the write
//   for (unsigned int i = 0; i < text.length(); i++) {
//     char character = text.charAt(i);
//     //Serial.println(character);
//     write(character);

//   }
// }

//----------- old method end -----------
