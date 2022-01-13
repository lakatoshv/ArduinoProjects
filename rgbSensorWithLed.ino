/// <summary>
/// Use RGB sensor with LED.
/// </summary>
// <copyright file="rgbSensorWithLed.ino" company="lakatoshvv">
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
    delay(100);
}

