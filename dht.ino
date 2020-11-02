/// <summary>
/// Use dht sensor.
/// </summary>
// <copyright file="laser.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

// humidity temperature sensor libraries
#include <Adafruit_Sensor.h>
#include "DHT.h"

// Liquid crystal display libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int DHT_PIN 2;


#define DHT_TYPE DHT11   
// DHT 21 (AM2301)
// DHT 22  (AM2302), AM2321

DHT dht(DHT_PIN, DHT_TYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  lcd.init();
  lcd.backlight();

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  printHumidity(h);
  
  printTemperature(t, f);

  printHeatIndex(c, f, h);
}

/// <summary>
/// Display humidity.
/// </summary>
void printHumidity(float humidity) {
  Serial.print(F("Humidity: "));
  Serial.print(humidity);
  
  lcd.clear();
  lcd.print("Humidity: ");
  lcd.print(humidity);
}

/// <summary>
/// Display temperature.
/// </summary>
void printTemperature(float c, float f) {
  Serial.print(F("%  Temperature: "));
  Serial.print(c);
  Serial.print(F("°C "));

  lcd.clear();
  lcd.print("Temperature(°C): ");
  lcd.print(c);
  
  Serial.print(f);
  
  lcd.clear();
  lcd.print("Temperature(°F ): ");
  lcd.print(f);
  
  Serial.print(F("°F "));
}

/// <summary>
/// Display heat index.
/// </summary>
void printHeatIndex(float c, float f, float h) {
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(c, h, false);

  Serial.print(F(" Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  
  lcd.clear();
  lcd.print("Heat index(°C): ");
  lcd.print(hic);
  
  Serial.print(hif);
  Serial.println(F("°F"));
  
  lcd.clear();
  lcd.print("Heat index(°F): ");
  lcd.print(hif);
}