#include <ESP8266WiFi.h>
#include <Arduino.h>


const char* ssid     = "ssid";
const char* password = "pass";



// From 
// https://github.com/esp8266/Arduino/issues/2627
// Also has WIFI Ex
//

const short int BUILTIN_LED1 = 2; //GPIO2

void setup() {
    // put your setup code here, to run once:
    pinMode(BUILTIN_LED1, OUTPUT);

    Serial.begin(115200);
    delay(10);

    Serial.print("\nConnecting to ");
    Serial.println(ssid);

    //We don't want the ESP to act as an AP
    //WiFi.mode(WIFI_STA); 
    //Serial.print("\nWifi Mode set to WIFI_STA");
    WiFi.begin(ssid, password);
    Serial.print("\nWifi begin called\n");

    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }

    Serial.println("");
    Serial.println("\nWiFi connected.");  
    Serial.print("\nIP address: ");
    Serial.println(WiFi.localIP());    
}

void loop() {

    Serial.printf("Number of connected devices (stations) = %d\n", WiFi.softAPgetStationNum());
    delay(3000);
    
    // put your main code here, to run repeatedly:
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(5000);              // wait for 5 seconds
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(500);              // wait for a half second    
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);              // wait for a second
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second    
}
