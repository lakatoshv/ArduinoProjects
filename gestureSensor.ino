/// <summary>
/// Use gesture sensor.
/// </summary>
// <copyright file="gestureSensor.iso" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

#include <Arduino_APDS9960.h>

String gesture = "";
String getGestureString() {
  int gesture = APDS.readGesture();
  switch(gesture) {
  case 0:
    return "UP";
    break;
  case 1:
    return "DOWN";
    break;
  case 2:
    return "LEFT";
    break;
  case 3:
    return "RIGHT";
    break;
  default:
    return "NONE"; 
    break;       
  }
}


void setup()
{
  if (!APDS.begin()) {
    Serial.println("Error initializing APDS9960 sensor.");
  }
}

void loop()
{
  if (APDS.gestureAvailable())
  {
    gesture = getGestureString();
  }

  Serial.println(gesture);
}

