/// <summary>
/// Use cooler.
/// </summary>
// <copyright file="cooler.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int COOLER_PIN = 3;

void setup() {
    pinMode(COOLER_PIN, OUTPUT);
}

void loop() {
    digitalWrite(COOLER_PIN, HIGH);
    delay(5000);
    digitalWrite(COOLER_PIN, LOW);
    delay(3000);
}