# Draw Bitmap SSD1351 Library

This library allows you to draw RGB bitmaps on an SSD1351 OLED display using the Ucglib library.

## Installation

1. Download the library ZIP file from the GitHub repository.
2. In the Arduino IDE, go to Sketch -> Include Library -> Add .ZIP Library.
3. Select the downloaded ZIP file.

## Usage

### Quick Start

1. Include the required libraries in your Arduino sketch:

```cpp
#include <SPI.h>
#include "Ucglib.h"
#include <avr/pgmspace.h>
#include "draw_bitmap_ssd1351.h"
```
Create an instance of the Ucglib_SSD1351_18x128x128_SWSPI class with your preferred pin configurations:

```cpp
Ucglib_SSD1351_18x128x128_SWSPI ucg(/*sclk=*/13, /*data=*/11, /*cd=*/7, /*cs=*/10, /*reset=*/8);
```
Create an instance of the DrawBitmapSSD1351 class:

```cpp
DrawBitmapSSD1351 drawBmp;
```
Create an array with your image data (replace "Bitmap image array" with your actual image data array). 
For the image conversion, I recommend the website: "https://notisrac.github.io/FileToCArray/":

```cpp
static const uint16_t example[] PROGMEM = {
    // Your image data goes here
};
```
In the setup function, initialize the serial communication, the Ucglib display, and draw the RGB bitmap:

```cpp
void setup(void) {
    Serial.begin(9600);
    delay(1000);

    ucg.begin(UCG_FONT_MODE_NONE);
    ucg.clearScreen();

    // HAS TO BE EXPLAINED FURTHER
    drawBmp.RGBBitmap(30, 34, 59, 67, example);

    Serial.println("Image drawn");
}
```
Upload the sketch to your Arduino board.

## Problems
If you have the problem that the array is too large, i recommend formatting the converted image using this website: "https://formatter.org/cpp-formatter"

## Contributing
Contributions are welcome! Please open an issue or submit a pull request.

## License
This library is licensed under the GNU GPL License.
