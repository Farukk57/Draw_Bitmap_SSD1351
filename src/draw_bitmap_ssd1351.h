#ifndef DRAW_BITMAP_SSD_1351_H_
#define DRAW_BITMAP_SSD_1351_H_

// Include necessary libraries and dependencies
#include <Arduino.h>
#include <Ucglib.h>

// Declare an external instance of the Ucglib_SSD1351_18x128x128_SWSPI class
extern Ucglib_SSD1351_18x128x128_SWSPI ucg;

// Class declaration for DrawBitmapSSD1351
class DrawBitmapSSD1351
{
public:
    // Public method declaration for drawing an RGB bitmap on the SSD1351 display
    void RGBBitmap(uint8_t pos_x, uint8_t pos_y, uint8_t height, uint8_t width, const uint16_t bitmap[]);
};

#endif /* DRAW_BITMAP_SSD_1351_H_ */