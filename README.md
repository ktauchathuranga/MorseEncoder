# MorseEncoder

MorseEncoder is a Arduino library for Encoding Strings to Morse Code(Audio).

## Installation

Use the Arduino Library manager to install MorseEncoder.

```bash
Sketch -> Include Library -> Add .ZIP Library...
```

## Usage

```cpp
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
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

