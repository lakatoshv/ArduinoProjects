/// <summary>
/// Use laser.
/// </summary>
// <copyright file="laser.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int LASER_PIN = 10;
const int PUSH_BUTTON_SWITCH_PIN = 4;

void setup ()
{
    pinMode(LASER_PIN, OUTPUT);
    pinMode(switchPin, INPUT);
}

void loop () {
    // if button is pressed turn on laser
    if (digitalRead(PUSH_BUTTON_SWITCH_PIN) == HIGH)
    {
        digitalWrite(LASER_PIN, HIGH);
    }
    else{
        digitalWrite(LASER_PIN, LOW);
    }
}