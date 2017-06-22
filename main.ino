#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "DHT.h"
 
const char* ssid = "myWifi";
const char* password = "password";
 
#define DHTPIN D4     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

HTTPClient http;    //Declare object of class HTTPClient
const int sleepTimeS = 300; // Time to sleep (in seconds)
 
void setup() 
{
  Serial.begin(115200);
  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
  dht.begin(); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected"); 
}
 
void loop() 
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }         

  //post data
  http.begin("http://things.ubidots.com/api/v1.6/devices/myDevice?token=xxxxxxxxxxxxxxxxxxx");      //Specify request destination
  http.addHeader("Content-Type", "application/json");  //Specify content-type header
  String data = "{\"temperatura\": ";
  data += t;
  data += ", \"vlaga\": ";
  data += h;
  data += "}";
   
  int httpCode = http.POST(data);   //Send the request
  String payload = http.getString();                  //Get the response payload
  //Serial.println(httpCode);   //Print HTTP return code
  Serial.println("payload: "+payload);    //Print request response payload 
  http.end();  //Close connection
  //end post data
  
  delay(sleepTimeS * 1000); //sleep 10min 
}
