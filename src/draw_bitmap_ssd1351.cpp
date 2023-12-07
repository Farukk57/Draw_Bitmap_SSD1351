#include "draw_bitmap_ssd1351.h"

// Implementation of the RGBBitmap function
void DrawBitmapSSD1351::RGBBitmap(uint8_t pos_x, uint8_t pos_y, uint8_t height, uint8_t width, const uint16_t bitmap[]) {
    // Loop through each pixel in the specified region
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Read the color value from the PROGMEM array
            uint16_t color = pgm_read_dword(&(bitmap[y * width + x]));

            // Extracting RGB components from the color value
            uint8_t red = (color & 0xF800) >> 8;
            uint8_t green = (color & 0x07E0) >> 3;
            uint8_t blue = (color & 0x001F) << 3;

            // Set color on the display using ucg.setColor
            ucg.setColor(red, green, blue);

            // Draw the pixel on the display at the specified position
            ucg.drawPixel(x + pos_x, y + pos_y);
        }
    }
}