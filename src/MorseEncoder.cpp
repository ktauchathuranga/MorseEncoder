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
  char* _text = new char[text.length() + 1];
  strcpy(_text, text.c_str());
  int len = strlen(_text);
  for (int i = 0; i < len; i++) {
    char oneLetter = (_text[i]);
    switch (oneLetter) {
      case 'A': A(mode); break;
      case 'B': B(mode); break;
      case 'C': C(mode); break;
      case 'D': D(mode); break;
      case 'E': E(mode); break;
      case 'F': LF(mode); break;
      case 'G': G(mode); break;
      case 'H': H(mode); break;
      case 'I': I(mode); break;
      case 'J': J(mode); break;
      case 'K': K(mode); break;
      case 'L': L(mode); break;
      case 'M': M(mode); break;
      case 'N': N(mode); break;
      case 'O': O(mode); break;
      case 'P': P(mode); break;
      case 'Q': Q(mode); break;
      case 'R': R(mode); break;
      case 'S': S(mode); break;
      case 'T': T(mode); break;
      case 'U': U(mode); break;
      case 'V': V(mode); break;
      case 'W': W(mode); break;
      case 'X': X(mode); break;
      case 'Y': Y(mode); break;
      case 'Z': Z(mode); break;
      case ' ': space(); break;
      case '0': N0(mode); break;
      case '1': N1(mode); break;
      case '2': N2(mode); break;
      case '3': N3(mode); break;
      case '4': N4(mode); break;
      case '5': N5(mode); break;
      case '6': N6(mode); break;
      case '7': N7(mode); break;
      case '8': N8(mode); break;
      case '9': N9(mode); break;
      case '.': SfullStop(mode); break;
      case ':': Scolon(mode); break;
      case ',': Scomma(mode); break;
      case ';': Ssemicolon(mode); break;
      case '?': Squestion(mode); break;
      case '=': Sequal(mode); break;
      case '\'': Ssquotation(mode); break;
      case '/': Sslash(mode); break;
      case '!': Sexclamation(mode); break;
      case '-': Shyphen(mode); break;
      case '_': Sunderscore(mode); break;
      case '"': Sdquotation(mode);; break;
      case '(': Slbracket(mode); break;
      case ')': Srbracket(mode); break;
      case '$': Sdollar(mode); break;
      case '&': Sampersand(mode); break;
      case '@': Sat(mode); break;
      case '+': Splus(mode); break;
    }
  }
}
