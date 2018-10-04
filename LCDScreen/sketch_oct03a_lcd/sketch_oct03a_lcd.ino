#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
// or #include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
// For a connection via I2C using brzo_i2c (must be installed) include
// #include <brzo_i2c.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Brzo.h"
// #include "SH1106Brzo.h"
// For a connection via SPI include
// #include <SPI.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Spi.h"
// #include "SH1106SPi.h"

// Include custom images
// #include "images.h"

// Initialize the OLED display using SPI
// D5 -> CLK
// D7 -> MOSI (DOUT)
// D0 -> RES
// D2 -> DC
// D8 -> CS
// SSD1306Spi        display(D0, D2, D8);
// or
// SH1106Spi         display(D0, D2);

// Initialize the OLED display using brzo_i2c
// D3 -> SDA
// D5 -> SCL
// SSD1306Brzo display(0x3c, D3, D5);
// or
// SH1106Brzo  display(0x3c, D3, D5);

// Initialize the OLED display using Wire library
SSD1306Wire  display(0x3c, D3, D5);
// SH1106 display(0x3c, D3, D5);


#define DEMO_DURATION 3000
typedef void (*Demo)(void);

int demoMode = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();


  // Initialising the UI will init the display too.
  display.init();

  display.flipScreenVertically();
  display.setContrast(255);
 

}

void loop() {
  // display.clear();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  // This should work for no screen flipping
  // Maybe a 50 for x coord
  //display.drawString(10, 10, "Hello Brad");

  display.drawString(50, 50, "Hello Brad");
    

  // X 0 IS RIGHT
  // Y 0 IS BOTTOM 
  // Y 64 IS BOTTOM FLIPPED
  // 128X64 
  display.drawVerticalLine(126, 0, 64);
  display.drawVerticalLine(120, 0, 64);
  display.drawVerticalLine(40, 0, 64);
  display.drawVerticalLine(30, 0, 64);
  display.drawVerticalLine(5, 0, 64);
  display.display();
}
