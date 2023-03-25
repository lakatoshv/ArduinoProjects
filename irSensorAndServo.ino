/// <summary>
/// Use IR sensor with servo.
/// </summary>
// <copyright file="irSensorAndServo.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <IRremote.h>
#include <Servo.h>

const int IR_SENSOR_PIN = 9;

IRrecv irrecv(IR_SENSOR_PIN);
Servo servo;

decode_results results;

void setup ()
{
    // Init Serila at 9600 Baud
    Serial.begin(9600); 
    Serial.println("Serial Working");
    
    irrecv.enableIRIn();
    servo.attach(2);
}

void loop () {
    int val = 0;
    if(irrecv.decode(results)) {
        Serial.println(results.value, HEX);
        irrecv.resume();

        if(results.value == plus) {
            val = val + 3;
        }
        if(results.value == minus) {
            val = val - 3;
        }

        if(val >= 0 && val <= 180) {
            servo.vrite(val);
        }
        delay(200);
    }
}