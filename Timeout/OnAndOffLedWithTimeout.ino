/// <summary>
/// Turn on and off Led with timeout.
/// </summary>
// <copyright file="OnAndOffLedWithTimeout.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

unsigned long previousAction;
int ledState = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  if(millis() - previousAction >= 500) {
    if(ledState == 0) {
        ledState = 1;
    }
    else {
        ledState = 0;
    }

    digitalWrite(13, ledState);
    previousAction = millis();
  }
}