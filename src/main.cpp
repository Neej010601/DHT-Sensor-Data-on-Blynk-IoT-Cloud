#define BLYNK_TEMPLATE_ID "TMPL_Yq5F5Xs"
#define BLYNK_DEVICE_NAME "Home Automation"
#define BLYNK_AUTH_TOKEN "5sDIvm0xwB2iNLnJjU-1cyuPDZWYSXVc"
#define BLYNK_PRINT Serial
 
 
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
 

char ssid[] = "Neej's Personal";
char pass[] = "tp010601";
 
#define DHTPIN 4      //connect with GPIO4
#define DHTTYPE DHT11 //DHT11 sensor
 
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

void sendSensor()
{
  int h = dht.readHumidity();
  int t = dht.readTemperature(); 

  if (isnan(h) || isnan(t)) { //isnan = is not a number
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V0, t); //Virtual Pin for Temp
  Blynk.virtualWrite(V1, h); //Virtual Pin for Humidity
}
 
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
timer.setInterval(10L, sendSensor);
}

void loop()
{
Blynk.run();
timer.run();
}