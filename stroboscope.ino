/// <summary>
/// Make stroboscope with leds.
/// </summary>
// <copyright file="stroboscope.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int POTENTIOMETER_PIN = A0;

const int LEDS_COUNT = 3;
const int LED_PINS[LEDS_COUNT] = { 11, 12 };

int potentiometerValue = 0;
int timer = 0;

void setup () {
    for (int i = 0; i < LEDS_COUNT; i++)
    {
        pinMode(LED_PINS[i], OUTPUT);
    }
}

void loop() {
    potentiometerValue = analogRead (POTENTIOMETER_PIN);
    timer = map(potentiometerValue, 0, 1023, 10, 500);

    for (int i = 0; i < LEDS_COUNT; i++)
    {

        digitalWrite(LED_PINS[i], HIGH);
        delay(timer);
        digitalWrite (LED_PINS[i], LOW) ;
        delay(timer);
        digitalWrite (LED_PINS[i], HIGH) ;
        delay(timer);
        digitalWrite (LED_PINS[i], LOW) ;
    }
}