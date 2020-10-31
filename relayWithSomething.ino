/// <summary>
/// Use relay with something.
/// </summary>
// <copyright file="relayWithSomething.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int RELAY_PIN = 3;
const int BUTTON_PIN = 4;

void setup() {
    pinMode(RELAY_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop() {
    if(digitalRead(BUTTON_PIN)){
      digitalWrite(RELAY_PIN, HIGH);
    }
    else {
      digitalWrite(RELAY_PIN, LOW);
    }
}

/// <summary>
/// Turn on of relay.
/// </summary>
void turnOnOfRelay() {
    digitalWrite(RELAY_PIN, HIGH);
    delay(5000);
    digitalWrite(RELAY_PIN, LOW);
    delay(3000);
}