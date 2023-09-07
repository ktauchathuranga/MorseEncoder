#ifndef MorseEncoder_h
#define MorseEncoder_h

class MorseEncoder {
public:
  //int unitTime = 80;                   // unit time in ms, if you want 15 WPM, unitTime = 1200 / 15
  //int audFreq = 100;

  MorseEncoder(int pin); // Constructor
  void begin(int wpm=15, int freq=600);
  void encode(String text);

private:
  int _pin;
  int _unitTime;
  int _freq;
  char _text[];

  void dot(){
      
      tone(_pin,_freq);
      delay(_unitTime);
      noTone(_pin);
      delay(_unitTime);
  }
  void dash(){
      tone(_pin,_freq);
      delay(3*_unitTime);
      noTone(_pin);
      delay(_unitTime);
  }
  void space(){
      delay(6*_unitTime); // cuz every dot and dash end with one unit, (actuall space 7 unit)
  }
  void letterSpace(){
      delay(_unitTime*2);
  }

  void A(){
      dot();
      dash();
      letterSpace();
  }
  void B(){
      dash();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void C(){
      dash();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void D(){
      dash();
      dot();
      dot();
      letterSpace();
  }
  void E(){
      dot();
      letterSpace();
  }
  void LF(){
      dot();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void G(){
      dash();
      dash();
      dot();
      letterSpace();
  }
  void H(){
      dot();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void I(){
      dot();
      dot();
      letterSpace();
  }
  void J(){
      dot();
      dash();
      dash();
      dash();
      letterSpace();
  }
  void K(){
      dash();
      dot();
      dash();
      letterSpace();
  }
  void L(){
      dot();
      dash();
      dot();
      dot();
      letterSpace();
  }
  void M(){
      dash();
      dash();
      letterSpace();
  }
  void N(){
      dash();
      dot();
      letterSpace();
  }
  void O(){
      dash();
      dash();
      dash();
      letterSpace();
  }
  void P(){
      dot();
      dash();
      dash();
      dot();
      letterSpace();
  }
  void Q(){
      dash();
      dash();
      dot();
      dash();
      letterSpace();
  }
  void R(){
      dot();
      dash();
      dot();
      letterSpace();
  }
  void S(){
      dot();
      dot();
      dot();
      letterSpace();
  }
  void T(){
      dash();
      letterSpace();
  }
  void U(){
      dot();
      dot();
      dash();
      letterSpace();
  }
  void V(){
      dot();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void W(){
      dot();
      dash();
      dash();
      letterSpace();
  }
  void X(){
      dash();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void Y(){
      dash();
      dot();
      dash();
      dash();
      letterSpace();
  }
  void Z(){
      dash();
      dash();
      dot();
      dot();
      letterSpace();
  }
  void N0(){
      dash();
      dash();
      dash();
      dash();
      dash();
      letterSpace();
  }
  void N1(){
      dot();
      dash();
      dash();
      dash();
      dash();
      letterSpace();
  }
  void N2(){
      dot();
      dot();
      dash();
      dash();
      dash();
      letterSpace();
  }
  void N3(){
      dot();
      dot();
      dot();
      dash();
      dash();
      letterSpace();
  }
  void N4(){
      dot();
      dot();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void N5(){
      dot();
      dot();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void N6(){
      dash();
      dot();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void N7(){
      dash();
      dash();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void N8(){
      dash();
      dash();
      dash();
      dot();
      dot();
      letterSpace();
  }
  void N9(){
      dash();
      dash();
      dash();
      dash();
      dot();
      letterSpace();
  }
  void SfullStop(){
      dot();
      dash();
      dot();
      dash();
      dot();
      dash();
      letterSpace();
  }
  void Scolon(){
      dash();
      dash();
      dash();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void Scomma(){
      dash();
      dash();
      dot();
      dot();
      dash();
      dash();
      letterSpace();
  }
  void Ssemicolon(){
      dash();
      dot();
      dash();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void Squestion(){
      dot();
      dot();
      dash();
      dash();
      dot();
      dot();
      letterSpace();
  }
  void Sequal(){
      dash();
      dot();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void Ssquotation(){
      dot();
      dash();
      dash();
      dash();
      dash();
      dot();
      letterSpace();
  }
  void Sslash(){
      dash();
      dot();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void Sexclamation(){
      dash();
      dot();
      dash();
      dot();
      dash();
      dash();
      letterSpace();
  }
  void Shyphen(){
      dash();
      dot();
      dot();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void Sunderscore(){
      dot();
      dot();
      dash();
      dash();
      dot();
      dash();
      letterSpace();
  }
  void Sdquotation(){
      dot();
      dash();
      dot();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void Slbracket(){
      dash();
      dot();
      dash();
      dash();
      dot();
      letterSpace();
  }
  void Srbracket(){
      dash();
      dot();
      dash();
      dash();
      dot();
      dash();
      letterSpace();
  }
  void Sdollar(){
      dot();
      dot();
      dot();
      dash();
      dot();
      dot();
      dash();
      letterSpace();
  }
  void Sampersand(){
      dot();
      dash();
      dot();
      dot();
      dot();
      letterSpace();
  }
  void Sat(){
      dot();
      dash();
      dash();
      dot();
      dash();
      dot();
      letterSpace();
  }
  void Splus(){
      dot();
      dash();
      dot();
      dash();
      dot();
      letterSpace();
  }
  // Add other private variables and functions here if needed
};

#endif
