/// <summary>
/// Change Led on external interrupt.
/// </summary>
// <copyright file="ChangeLedOnExternalInterrupt.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

volatile int ledState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  attachInterrupt(0, changePin, FALLING);
}

void loop() {
  delay(1000);
}

void changePin() {
    ledState = 1 - ledState;
    digitalWrite(13, ledState);
}