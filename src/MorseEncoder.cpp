#include "Arduino.h"
#include "MorseEncoder.h"

MorseEncoder::MorseEncoder(int pin) {
  _pin = pin;
}

void MorseEncoder::begin(int wpm=15, int freq=600) {
  _unitTime = 1200 / wpm;
  _freq = freq;

  pinMode(_pin, OUTPUT);
  //Serial.begin(9600);
}

void MorseEncoder::encode(String text) {
  text.toUpperCase();
  char* _text = new char[text.length() + 1];
  strcpy(_text, text.c_str());
  int len = strlen(_text);
      for (int i=0;i<len;i++) {
        char oneLetter = (_text[i]);
        switch(oneLetter) { 
          case 'A': A(); break;
          case 'B': B(); break;
          case 'C': C(); break;
          case 'D': D(); break;
          case 'E': E(); break;
          case 'F': LF(); break;
          case 'G': G(); break;
          case 'H': H(); break;
          case 'I': I(); break;
          case 'J': J(); break;
          case 'K': K(); break;
          case 'L': L(); break;
          case 'M': M(); break;
          case 'N': N(); break;
          case 'O': O(); break;
          case 'P': P(); break;
          case 'Q': Q(); break;
          case 'R': R(); break;
          case 'S': S(); break;
          case 'T': T(); break;
          case 'U': U(); break;
          case 'V': V(); break;
          case 'W': W(); break;
          case 'X': X(); break;
          case 'Y': Y(); break;
          case 'Z': Z(); break;
          case ' ': space(); break;
          case '0': N0(); break;
          case '1': N1(); break;
          case '2': N2(); break;
          case '3': N3(); break;
          case '4': N4(); break;
          case '5': N5(); break;
          case '6': N6(); break;
          case '7': N7(); break;
          case '8': N8(); break;
          case '9': N9(); break;
          case '.': SfullStop(); break;
          case ':': Scolon(); break;
          case ',': Scomma(); break;
          case ';': Ssemicolon(); break;
          case '?': Squestion(); break;
          case '=': Sequal(); break;
          case '\'': Ssquotation(); break;
          case '/': Sslash(); break;
          case '!': Sexclamation(); break;
          case '-': Shyphen(); break;
          case '_': Sunderscore(); break;
          case '"': Sdquotation();; break;
          case '(': Slbracket(); break;
          case ')': Srbracket(); break;
          case '$': Sdollar(); break;
          case '&': Sampersand(); break;
          case '@': Sat(); break;
          case '+': Splus(); break;
        }
      }
}
