
#include <ESP8266WiFi.h>
#include <Arduino.h>

const char* ssid     = "ASSID";
const char* password = "PASSWORD";



const short int BUILTIN_LED1 = 2; //GPIO2




int wifiStatus;

void setup() {

  pinMode(BUILTIN_LED1, OUTPUT);

  // delay(1000);
  Serial.begin(115200);
  Serial.print("Start");
  Serial.println();
  Serial.println();
  Serial.print("Configuring WiFi access point...");



  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Your are connecting to;");
  Serial.println(ssid);

  //Serial.print("Setting Wifi Mode to Station");
  //WiFi.mode(WIFI_STA);
  //Serial.print("Wifi Mode Set");

  // sWiFi.disconnect();
  // WiFi.setOutputPower(0);

  Serial.print("WIFI Begin");
  WiFi.begin(ssid, password);
  Serial.print("After WIFI Begin");

  Serial.print("WIFI Status: ");
  Serial.print(WiFi.status());

  // typedef enum {
  //     WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
  //     WL_IDLE_STATUS      = 0,
  //     WL_NO_SSID_AVAIL    = 1,
  //     WL_SCAN_COMPLETED   = 2,
  //     WL_CONNECTED        = 3,
  //     WL_CONNECT_FAILED   = 4,
  //     WL_CONNECTION_LOST  = 5,
  //     WL_DISCONNECTED     = 6
  // } wl_status_t;


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(":");
    delay(200);
    Serial.print(".");
  }

}

void loop() {

  wifiStatus = WiFi.status();

  if (wifiStatus == WL_CONNECTED) {
    Serial.println("");
    Serial.println("Your ESP is connected!");
    Serial.println("Your IP address is: ");
    Serial.println(WiFi.localIP());
    digitalWrite(BUILTIN_LED1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(3000);              // wait for a second
    digitalWrite(BUILTIN_LED1, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);              // wait for a second        
  }
  else {
    Serial.println("");
    Serial.println("WiFi not connected");
  }
  delay(1000); // check for connection every once a second
}
