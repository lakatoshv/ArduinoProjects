/// <summary>
/// External interrupt.
/// </summary>
// <copyright file="ExternalInterrupt.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

volatile int counter;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, buttonTick, FALLING);
}

void loop() {
  Serial.println(counter);
  delay(1000);
}

void buttonTick() {
    counter++;
}