#include <WiFi.h>
#include "main.h" //Own Made library including all the blynk and DHT code.

void setup()
{
Serial.begin(monitor);
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(10L, sendSensor);
}

void loop()
{
Blynk.run();
timer.run();
}