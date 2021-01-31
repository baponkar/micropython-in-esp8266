/***************************************************************************
  This is a library for the BMP280 humidity, temperature & pressure sensor
  This example shows how to take Sensor Events instead of direct readings
  
  Designed specifically to work with the Adafruit BMP280 Breakout
  ----> http://www.adafruit.com/products/2651

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_BMP280.h>
#include <TimeLib.h>
#include <WidgetRTC.h>


Adafruit_BMP280 bmp; // use I2C interface
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();






// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = " 9PjpcgitFJKh-DIDZ2dRaetvas8qG-I8";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "AndroidAP";
char pass[] = "beta_876";
BlynkTimer timer;
WidgetRTC rtc;
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void clockDisplay()
{
  String currentTime = String(hour()) + " " + minute() + " " + second();
  String currentDate = String(day()) + " " + month() + " " + year();
  Serial.print("Current Time: ");
  Serial.print(currentTime);
  Serial.print("Current Date:");
  Serial.print(currentDate);
  Serial.println();


}

BLYNK_CONNECTED(){
    rtc.begin();
  }


void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, millis() / 1000);
}

void mySensorEvent()
{
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  float  temp = temp_event.temperature;
  float pressure = pressure_event.pressure;
  float altitude = pressure/(13.6*9.80);
  
  Blynk.virtualWrite(V5,temp);
  Blynk.virtualWrite(V6,pressure);
  Blynk.virtualWrite(V7,altitude);

  if ( temp < 10)
  {
    Blynk.notify("It is a Extream Winter!");
    Blynk.email("Baponkar600@gmail.com","ESP8266 Sensor alert!","It is a Extream Winter!");
  }
  else if ( temp > 40)
  {
    Blynk.notify("It is a Extream hot!");
     Blynk.email("Baponkar600@gmail.com","ESP8266 Sensor alert!","It is a Extream hot!");
  }

  
}



void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 Sensor event test"));

  Blynk.begin(auth, ssid, pass);
  //timer.setInterval(1000L, myTimerEvent);
  timer.setInterval(1000L,mySensorEvent);
  timer.setInterval(500L,clockDisplay);

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1) delay(10);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  bmp_temp->printSensorDetails();
}

void loop() {
   Blynk.run();
   timer.run();
  sensors_event_t temp_event, pressure_event;
  bmp_temp->getEvent(&temp_event);
  bmp_pressure->getEvent(&pressure_event);
  
  Serial.print(F("Temperature = "));
  Serial.print(temp_event.temperature);
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(pressure_event.pressure);
  Serial.println(" hPa");

  Serial.println();
  delay(2000);
}
