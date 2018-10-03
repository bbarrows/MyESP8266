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
