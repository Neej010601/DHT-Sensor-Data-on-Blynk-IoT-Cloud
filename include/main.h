#ifndef SECRET_H_
#define SECRET_H_

#define BLYNK_TEMPLATE_ID "TMPL_Yq5F5Xs" //blynk function
#define BLYNK_DEVICE_NAME "Home Automation" //blynk function
#define BLYNK_AUTH_TOKEN "5sDIvm0xwB2iNLnJjU-1cyuPDZWYSXVc" //blynk function
#define BLYNK_PRINT Serial //blynk function

#include <BlynkSimpleEsp32.h> //blynk library
#include <DHT.h> //DHT library

#define monitor 9600

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "Neej's Personal"; //ssid of WiFi
char pass[] = "tp010601"; //password of WiFi
char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void sendSensor()
{
  int h = dht.readHumidity();
  int t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) { //isnan = is not a number
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

#endif