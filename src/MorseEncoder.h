#ifndef MorseEncoder_h
#define MorseEncoder_h

class MorseEncoder {
  public:
    //int unitTime = 80;                   // unit time in ms, if you want 15 WPM, unitTime = 1200 / 15
    //int audFreq = 100;

    MorseEncoder(int pin); // Constructor
    void beginAudio(int wpm = 15, int freq = 600);
    void beginLight(int wpm = 15);
    void encodeAudio(String text);
    void encodeLight(String text);

  private:
    int _pin;
    int _unitTime;
    int _freq;

    void encode(String text, int mode);

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
      delay(6 * _unitTime); // cuz every dot and dash end with one unit, (actuall space 7 unit)
    }
    void letterSpace() {
      delay(_unitTime * 2);
    }

    void A(int mode) {
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void B(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void C(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void D(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void E(int mode) {
      dot(mode);
      letterSpace();
    }
    void LF(int mode) {
      dot(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void G(int mode) {
      dash(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void H(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void I(int mode) {
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void J(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void K(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void L(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void M(int mode) {
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void N(int mode) {
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void O(int mode) {
      dash(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void P(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Q(int mode) {
      dash(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void R(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void S(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void T(int mode) {
      dash(mode);
      letterSpace();
    }
    void U(int mode) {
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void V(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void W(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void X(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Y(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void Z(int mode) {
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void N0(int mode) {
      dash(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void N1(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void N2(int mode) {
      dot(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void N3(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void N4(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void N5(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void N6(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void N7(int mode) {
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void N8(int mode) {
      dash(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void N9(int mode) {
      dash(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void SfullStop(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Scolon(int mode) {
      dash(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void Scomma(int mode) {
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void Ssemicolon(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Squestion(int mode) {
      dot(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void Sequal(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Ssquotation(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Sslash(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Sexclamation(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      letterSpace();
    }
    void Shyphen(int mode) {
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Sunderscore(int mode) {
      dot(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Sdquotation(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Slbracket(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Srbracket(int mode) {
      dash(mode);
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Sdollar(int mode) {
      dot(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dash(mode);
      letterSpace();
    }
    void Sampersand(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      dot(mode);
      dot(mode);
      letterSpace();
    }
    void Sat(int mode) {
      dot(mode);
      dash(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    void Splus(int mode) {
      dot(mode);
      dash(mode);
      dot(mode);
      dash(mode);
      dot(mode);
      letterSpace();
    }
    // Add other private variables and functions here if needed
};

#endif
