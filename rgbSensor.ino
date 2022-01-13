/// <summary>
/// Use RGB sensor.
/// </summary>
// <copyright file="rgbSensor.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Arduino_APDS9960.h>

int red = 0;
int green = 0;
int blue = 0;

void setup()
{
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor.");
  }
  red = 0;
  green = 0;
  blue = 0;
}

void loop()
{
  if (APDS.colorAvailable())
  {
    APDS.readColor(red, green, blue);
  }

  
    Serial.println("Red = " + red);
    Serial.println("Green =" + green);
    Serial.println("Blue = " + blue);
}

