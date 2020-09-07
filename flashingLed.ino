/// <summary>
/// Turns on flash lights.
/// </summary>
// <copyright file="flashingLed.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

// Led pins
int LED_PIN7 = 7;
int LED_PIN8 = 8;

void setup()
{
    pinMode(LED_PIN7, OUTPUT);
    pinMode(LED_PIN8, OUTPUT);
}

void loop()
{
    turnLightsOn();
    turnLightsOff();
}

/// <summary>
/// Turn Led lights on.
/// </summary>
void turnLightsOn()
{
    digitalWrite(LED_PIN7, HIGH);
    digitalWrite(LED_PIN8, HIGH);
    delay(1000);
}

/// <summary>
/// Turn Led lights off.
/// </summary>
void turnLightsOff()
{
    digitalWrite(LED_PIN7, LOW);
    digitalWrite(LED_PIN8, LOW);
    delay(1000);
}