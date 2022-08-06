/// <summary>
/// Use gesture sensor with servo.
/// </summary>
// <copyright file="gestureSensorWithServo.ino" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Arduino_APDS9960.h>
#include <Servo.h>

String gesture = "";
Servo servo;

int gesture;
void setup()
{
  servo.attach(2);
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor.");
  }
}

void loop()
{
  if (APDS.gestureAvailable())
  {
    gesture = APDS.readGesture();
  }

  servo.write(0);
  delay(2000);
  servo.write(180);
  delay(2000);
}

/// <summary>
/// Turn servo.
/// </summary>
/// <param name="ledPin">led pin.</param>
/// <param name="gestureValue">gesture value.</param>
turnServo(String gestureValue){
    switch(gesture) {
        case 0:
            servo.write(0);
            break;
        case 1:
            servo.write(180);
            break;
        case 2:
            servo.write(45);
            break;
        case 3:
            servo.write(135);
            break;
        default:
            break;       
  }
}