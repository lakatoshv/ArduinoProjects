/// <summary>
/// Use buzzer.
/// </summary>
// <copyright file="buzzer.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int BUZZER_PIN = 11;

void setup(){
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop(){
  // Send 1KHz sound signal for 1 sec
  tone(BUZZER_PIN, 1000); 
  delay(1000);
  noTone(BUZZER_PIN);
  delay(1000);
}