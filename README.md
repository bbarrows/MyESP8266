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


