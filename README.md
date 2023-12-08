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
#include "Ucglib.h"
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
Create an array with your image data (replace "Bitmap image array" with your actual image data array):

```cpp
static const uint16_t example[] PROGMEM = {
    // Your image data goes here
};
```
In the setup function, initialize the serial communication, the Ucglib display, and draw the RGB bitmap. In the RGBBitmap function, you have 5 Parameters, the first two Parameters are for the X and Y position of the Image on the Display, and the third and fourth parameters are for the height and width of your converted Image. The last parameter is for your bitmap array, input the name you gave the array. 

```cpp
void setup(void) {
    Serial.begin(9600);
    delay(1000);

    ucg.begin(UCG_FONT_MODE_NONE);
    ucg.clearScreen();

    // 1. pos_x, 2. pos_y 3. height, 4. width, 5. image array variable
    drawBmp.RGBBitmap(30, 34, 59, 67, example);

    Serial.println("Image drawn");
}
```
Upload the sketch to your Arduino board.

## Image conversion
For the image conversion, I recommend the website: "https://notisrac.github.io/FileToCArray/". Be sure to use 
1. Code format: Hex
2. Palette mod: RRRRRGGGGGGBBBBB (2byte/pixel), R5G6B5
3. Endianness: Little-endian
4. static; const; Data type: uint16_t; PROGMEM

## Problems
If you have the problem that the array is too large, i recommend formatting the converted image using this website: "https://formatter.org/cpp-formatter"

## Contributing
Contributions are welcome! Please open an issue or submit a pull request.

## License
This library is licensed under the GNU GPL License.
