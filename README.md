# **MorseEncoder**
### _Morseencoder is an Arduino library for encoding data to Morse code (Audio and light)._
Introducing the MorseEncoder library, a tool that converts various data types to Morse codes, including **integers, longs, characters, character arrays, and strings.** it can be encoded as [AUDIO](https://github.com/ktauchathuranga/MorseEncoder/blob/main/examples/MorseEncoder_EXAMPLE_AUDIO/MorseEncoder_EXAMPLE_AUDIO.ino) or [LIGHT](https://github.com/ktauchathuranga/MorseEncoder/blob/main/examples/MorseEncoder_EXAMPLE_LIGHT/MorseEncoder_EXAMPLE_LIGHT.ino) by your choice.

***
## Installation

1. Go to the [```Releases```](https://github.com/ktauchathuranga/MorseEncoder/releases) Page and download the latest version. 
2. Use the Arduino Library Manager to install MorseEncoder.

```bash
Sketch -> Include Library -> Add .ZIP Library...
```

Also, you can install the library directly from the Library Manager in the IDE.

```
Sketch -> Include Library -> Library Manger... -> Search for - MorseEncoder
```
## Usage

```c++
#include "MorseEncoder.h"

MorseEncoder morseA(9);       // Initialize with the desired pin for Audio **PWM pins only
MorseEncoder morseL(13);      // Initialize with the desired pin for Light

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM (word per minute) rate and frequency
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseA.print(message);   // [AUDIO] Broadcast encoded audio
  delay(2000);
  morseL.print(message);   // [LIGHT] Broadcast encoded light
  delay(2000);
}
```
or you can navigate to the Examples section of the Arduino IDE and find the example code there!

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.
Please make sure to update tests as appropriate.
and a big thanks goes to the dev friends in this [Arduino Forum](https://forum.arduino.cc/t/i-need-help-with-my-library/1167276/21)

## License

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
