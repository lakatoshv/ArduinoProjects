/// <summary>
/// Show milliseconds from start.
/// </summary>
// <copyright file="ShowMillisecondsFromStart.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(millis());
}