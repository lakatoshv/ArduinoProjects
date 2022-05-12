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

    turnOnRGBLed(RED_PIN, red);
    turnOnRGBLed(BLUE_PIN, blue);
    turnOnRGBLed(GREEN_PIN, green);
    delay(100);
}

/// <summary>
/// Turn on RGB led.
/// </summary>
/// <param name="ledPin">led pin.</param>
/// <param name="value">value.</param>
turnOnRGBLed(int ledPin, int value){
    analogWrite(ledPin, value);
}

