#ifndef MorseEncoder_h
#define MorseEncoder_h

const char* const morseCodes[36] PROGMEM = {
  ".-",    // A
  "-...",  // B
  "-.-.",  // C
  "-..",   // D
  ".",     // E
  "..-.",  // F
  "--.",   // G
  "....",  // H
  "..",    // I
  ".---",  // J
  "-.-",   // K
  ".-..",  // L
  "--",    // M
  "-.",    // N
  "---",   // O
  ".--.",  // P
  "--.-",  // Q
  ".-.",   // R
  "...",   // S
  "-",     // T
  "..-",   // U
  "...-",  // V
  ".--",   // W
  "-..-",  // X
  "-.--",  // Y
  "--..",  // Z
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----."  // 9
};

const char* const morseSpecialChars[17] PROGMEM = {
  ".-.-.-",  // .
  "--..--",  // ,
  "---...",  // :
  "-.-.-.",  // ;
  "..--..",  // ?
  "-...-",   // =
  "-..-.",   // /
  "-.-.--",  // !
  "-....-",  // -
  "..--.-",  // _
  ".-..-.",  // "
  "-.--.",   // (
  "-.--.-",  // )
  "...-..-", // $
  ".--.-.",  // @
  ".-...",   // &
  ".-.-."    // +
};

class MorseEncoder : public Print {
  public:
    //int unitTime = 80;                   // unit time in ms, if you want 15 WPM, unitTime = 1200 / 15
    //int audFreq = 100;

    MorseEncoder(int pin); // Constructor
    void beginAudio(int wpm, int freq); // removed default arguments cuz esp8266 giving me hard times
    void beginLight(int wpm);
    // void encodeAudio(String text);
    // void encodeLight(String text);
    // void encode(String text);
    unsigned int write(uint8_t character);
    using Print::write;

  private:
    int _pin;
    int _unitTime;
    int _freq;
    int _mode;



    void dot(int mode) {
      if (mode == 1) {
        tone(_pin, _freq);
        delay(_unitTime);
        noTone(_pin);
        delay(_unitTime);
      } else if (mode == 0) {
        digitalWrite(_pin, HIGH);
        delay(_unitTime);
        digitalWrite(_pin, LOW);
        delay(_unitTime);
      }
    }
    void dash(int mode) {
      if (mode == 1) {
        tone(_pin, _freq);
        delay(3 * _unitTime);
        noTone(_pin);
        delay(_unitTime);
      } else if (mode == 0) {
        digitalWrite(_pin, HIGH);
        delay(3 * _unitTime);
        digitalWrite(_pin, LOW);
        delay(_unitTime);
      }
    }
    void space() {
      delay(6 * _unitTime); // cuz every dot and dash end with one unit, (actual space 7 unit)
    }
    void letterSpace() {
      delay(_unitTime * 2);
    }
    // Add other private variables and functions here if needed
};

#endif
