# Whats going on

## Materials

* LCD LED Screen - LANMU 0.96" Inch I2C IIC SPI Serial 128X64 Yellow&Blue OLED LCD LED Display Module for Arduino Raspberry PI
  https://www.amazon.com/gp/product/B01G6SAWNY/ref=oh_aui_detailpage_o04_s01?ie=UTF8&psc=1

* HiLetgo 2pcs ESP8266 NodeMCU LUA CP2102 ESP-12E Internet WIFI Development Board Open source Serial Wireless Module Works Great with Arduino IDE/Micropython (Pack of 2PCS) 
  https://www.amazon.com/gp/product/B010N1SPRK/ref=oh_aui_detailpage_o04_s01?ie=UTF8&psc=1



* Getting started


SHORT VERSON

```

Install
https://s3.amazonaws.com/rbat.es/codebenderDriver.zip


Add this link to additonal boards manager option in arduino settings

http://arduino.esp8266.com/stable/package_esp8266com_index.json

add the board esp8266

Restart computer and compile!


```

Example blink project:
```

#include <Arduino.h>

// From 
// https://github.com/esp8266/Arduino/issues/2627
// Also has WIFI Ex
//

const short int BUILTIN_LED1 = 2; //GPIO2

void setup() {
    // put your setup code here, to run once:
    pinMode(BUILTIN_LED1, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(3000);              // wait for a second
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second    
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(2000);              // wait for a second
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second    
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second            
}


```

** Setup ardiuno IDE

https://www.hackster.io/auggujarat/getting-started-with-nodemcu-esp8266-on-arduino-ide-b7e18e

Add this link to additonal boards manager option in settings

http://arduino.esp8266.com/stable/package_esp8266com_index.json

** Install OSX Drivers

https://cityos-air.readme.io/docs/1-mac-os-usb-drivers-for-nodemcu

brew cask install Caskroom/cask/silicon-labs-vcp-driver

download
https://www.silabs.com/Support%20Documents/Software/Mac_OSX_VCP_Driver.zip

Alt guide

https://www.marginallyclever.com/2017/02/setup-nodemcu-drivers-arduino-ide/

http://www.robertprice.co.uk/robblog/nodemcu-lua-setup-using-mac/


This is an unsigned one that requires disabled kext signing
http://www.doit.am/CH341SER_MAC.ZIP

From 
http://rossbates.com/2016/01/30/getting-started-esp8266-osx/

Signed version here


LOOKS LIKE THIS IS THE DRIVER FOR 12E THAT WILL WORK!!!

https://s3.amazonaws.com/rbat.es/codebenderDriver.zip




# Firmware

USE THE WEBSITE
Its awesome

 http://nodemcu-build.com/


Or goto

 ~/repos/nodemcu-firmware
 and run

  docker run --rm -ti -v `pwd`:/opt/nodemcu-firmware marcelstoer/nodemcu-build build


sudo esptool.py -p /dev/tty.SLAB_USBtoUART   write_flash -fm dio  0x00000 ~/repos/nodemcu-firmware/bin/nodemcu_float_master_20181003-0458.bin 0x3fc000  ~/Downloads/ESP8266_NONOS_SDK-2.2.0/bin/esp_init_data_default_v08.bin 













# For LCD LED

https://www.amazon.com/gp/product/B01G6SAWNY/ref=oh_aui_detailpage_o04_s01?ie=UTF8&psc=1

It says that GND AND VCC  ARE REVERSED

ALSO:

You need the GOFi2cOLED library:
Once you have that installed, run the demo sketch listed on the site. I found that the I2C address for the display was not right in the demo. I ran I2C Scanner from Adafruit and found the address for my OLED was 0x3C. The sample sketch uses 0x3D. After I changed that and ran the sketch again it worked as expected. There will be no back-lighting or any indication the screen is operational when power and I2C is connected until the sketch is run. Hope this helps!

## PDF IN THIS FOLDER:
SOLOMON SYSTECH SSD1306 rev 1.1



AND

This part uses the SSD1306 driver, as opposed to SSD1308
I'm controlling this display with a MBED LPC1768 dev board (3.3v based)
OLED display Vcc = 3.3v
SDA/SCL @ 3.3V without pull-up resistors nor level shifts to LPC1768. I did use pull-ups w/o issues originally.

On the Mbed dev environment, i ended up using nkhorman/Adafruit_GFX SSD1306 library to get this display to power on.
The tech doc i'm referencing is: SOLOMON SYSTECH SSD1306 rev 1.1 (sorry i don't have the link to the pdf, just google for it)

Worth sharing:
- I was unable to power on the display with the SSD1308 drivers, wishfully thinking there'd be some backwards compat; From the reference docs, my guess is that the initialization sequence was different enough.
- There are other mbed SSD1306 libraries that didn't work, and did not power on the display. I wasted a lot of time on this and thought my board was bad.
- Regarding i2c address, some reviews noted that the device reports an address of 0x3C through use of i2c scanner. This is true, however, I was only able to communicate when using i2c address 0x78 (default resistor config). I thought this was very strange, but have not looked further into why.


YouTube videos

https://www.youtube.com/watch?v=wloWIyvw2w4
https://www.youtube.com/watch?v=A9EwJ7M7OsI


Pin out part
https://youtu.be/A9EwJ7M7OsI?t=187

This is an ESP8266 and my LED Screen
part1
https://www.youtube.com/watch?v=wloWIyvw2w4

part2
https://www.youtube.com/watch?v=clcNAb5unnk

part3
https://www.youtube.com/watch?v=clcNAb5unnk

No bullshit just the LED and board
https://youtu.be/bH-BW6gTnGI?t=11


HOW I2C WORKS
https://www.youtube.com/watch?v=6IAkYpmA1DQ







ESO8266 12 E pinmap

Pin Map
The Geekcreit site is all but empty and, as much as I searched, I could not find a map of the board pins on the DOIT sites. It does have a link to the NodeMCU GitHub site with a pin map of version 1.0 of its development kit. The labels correspond pretty much to those found on the V3 board from DOIT/GEEKCREIT. The following schema shows the two layouts. This is the view from above the board, the shield of the ESP module is visible and at the top, the micro USB connector is at the bottom.


              +---------------+
GPIO | DEVKIT |      DOIT     | DEVKIT | GPIO
     |  V1.0  |       V3      |  V1.0  |
-----|--------+---------------+--------------
     |    A0  | AD0        D0 |  D0    |  16
     |   RSV  | RSV       ~D1 |  D1    |   5
     |   RSV  | RSV       ~D2 |  D2    |   4
 10  |   SD3  | SD3       ~D3 |  D3    |   0
  9  |   SD2  | SD2       ~D4 |  D4    |   2
     |   SD1  | SD1       3V3 |  3V3   |
     |   CMD  | CMD       GND |  GND   |
     |   SD0  | SD0       ~D5 |  D5    |  14 
     |   CLK  | CLK       ~D6 |  D6    |  12
     |   GND  | GND       ~D7 |  D7    |  13
     |   3V3  | 3V3       ~D8 |  D8    |  15
     |    EN  | EN        RX< |  D9    |   3
     |   RST  | RST       TX> |  D10   |   1
     |   GND  | GND       GND |  GND   |
     |   Vin  | Vin       3V3 |  3V3   |
              +---------------+

        Not accurate, please see the conclusion


From
https://www.sigmdel.ca/michel/ha/esp8266/doit_nodemcu_v3_en.html


This wiring and this example work!!

https://youtu.be/U1TTFYCe2vg?t=113

My LCD Screen is mostly bad though prob due to shipping..

exmaples are at
https://github.com/ThingPulse/esp8266-oled-ssd1306/blob/master/examples/SSD1306SimpleDemo/SSD1306SimpleDemo.ino













