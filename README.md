# MorseEncoder

MorseEncoder is an Arduino library for Encoding Strings to Morse Code (Audio and Light).

## Installation

1. Go to the [```Releases```](https://github.com/ktauchathuranga/MorseEncoder/releases) and Download the latest version. 
2. Use the Arduino Library manager to install MorseEncoder.

```bash
Sketch -> Include Library -> Add .ZIP Library...
```

also, You can install the Library directly from the Library Manager in the IDE.

```
Sketch -> Include Library -> Library Manger... -> Search for - MorseEncoder
```

## Usage

```c++
#include "MorseEncoder.h"

MorseEncoder morseA(9);  // Initialize with the desired pin for Audio
MorseEncoder morseL(13); // Initialize with the desired pin for Light

void setup() {
  morseA.beginAudio(15, 500); // [AUDIO] Initialize WPM (word per minute) rate and frequency
  morseL.beginLight(15);      // [LIGHT] Initialize WPM (word per minute) rate
}

void loop() {
  String message = "sos";
  morseA.encodeAudio(message); // [AUDIO] Boradcast encoded audio
  delay(2000);
  morseL.encodeLight(message); // [LIGHT] Broadcast encoded light
  delay(2000);
}
```
or you can Navigate to the Examples of the Arduino IDE and find the Example code there!

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

