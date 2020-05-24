#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#include "DHTesp.h"  //DHT11 Library for ESP
  
#define LED 2        //On board LED
#define DHTpin 14    //D5 of NodeMCU is GPIO14

Adafruit_BMP280 bmp; // I2C Interface

DHTesp dht;
float temperature, humidity, pressure, altitude;

int smokeA0 = A0;
// Gas sensor's threshold value. You might need to change it.
int sensorThres = 600;
char* smoke = "!!! Attention, Smoke Detected, Possible Fire !!!";

/*Put your SSID & Password*/
const char* ssid = "Username";  // Enter SSID here
const char* password = "Password";  //Enter Password here

ESP8266WebServer server(80);              
 
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));

  if (!bmp.begin()) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  
  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");

// DHT setup 
  dht.setup(DHTpin, DHTesp::DHT11); //for DHT11 Connect DHT sensor to GPIO 17
  //dht.setup(DHTpin, DHTesp::DHT22); //for DHT22 Connect DHT sensor to GPIO 17

  //Onboard LED port Direction output
  pinMode(LED,OUTPUT);
}

void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  humidity = dht.getHumidity();
  temperature = dht.getTemperature();
  pressure = bmp.readPressure() / 100.0F;   //displaying the Pressure in hPa, you can change the unit
  altitude = bmp.readAltitude(1019.66);     //The "1019.66" is the pressure(hPa) at sea level in day in our region
                                            //If you don't know it, modify it until you get your current altitude
  Serial.print("H:");
  Serial.println(humidity);
  Serial.print("T:");
  Serial.println(temperature); //dht.toFahrenheit(temperature));
  Serial.print("P:");
  Serial.println(pressure);
  Serial.print("A:");
  Serial.println(altitude);
  
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
 if (analogSensor > sensorThres)
 {
   Serial.print("Attention!!! Smoke Detected, Possible fire !!! ");
 }
 else
 {
   Serial.print("No smoke, All clear !!! ");
   smoke="No smoke, All clear !!!";
 }
 delay(100); 
  
  server.send(200, "text/html", SendHTML(temperature,humidity, pressure,altitude,smoke)); 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
//HTML script
String SendHTML(float temperature, float humidity, float pressure,float altitude, char* smoke){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP8266 Robot Hood</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;background-color: #d8f2f4;}\n";
  ptr +="body{margin-top: 50px;}  h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #740469;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP8266 Robot Hood</h1>\n";
  ptr +="<p>Temperature: ";
  ptr +=temperature;
  ptr +="&deg;C</p>";
  ptr +="<p>Humidity: ";
  ptr +=humidity;
  ptr +="%</p>";
  ptr +="<p>Pressure: ";
  ptr +=pressure;
  ptr +="hPa</p>";
  ptr +="<p>Altitude: ";
  ptr +=altitude;
  ptr +="m</p>";
  ptr +="<p>Smoke: ";
  ptr +=smoke;
  ptr +="</p>";
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
