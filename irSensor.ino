/// <summary>
/// Use IR sensor.
/// </summary>
// <copyright file="irSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int IR_SENSOR_PIN = 9;
const int LED_PIN = 13;

void setup ()
{
    // Init Serila at 115200 Baud
    Serial.begin(115200); 
    Serial.println("Serial Working");
    
    pinMode(IR_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
}

void loop () {
    // Set the GPIO as Input
    int sensorStatus = digitalRead(IR_SENSOR_PIN); 
    // Check if the pin high or not
    if (sensorStatus == 1) {
        // if the pin is high turn off the onboard Led
        digitalWrite(LED_PIN, LOW);
        Serial.println("Motion Ended!");
    }
    else {
        //else turn on the onboard LED
        digitalWrite(LED_PIN, HIGH);
        Serial.println("Motion Detected!");
    }
}