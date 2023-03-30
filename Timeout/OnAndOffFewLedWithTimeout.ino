/// <summary>
/// Turn on and off few Led with timeout.
/// </summary>
// <copyright file="OnAndOffFewLedWithTimeout.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int LED_PIN1 = 11;
const int LED_PIN2 = 10;
const int LED_PIN3 = 9;

unsigned long previousAction1;
unsigned long previousAction2;
unsigned long previousAction3;

int ledState1 = 0;
int ledState2 = 0;
int ledState3 = 0;

int timeout1 = 1000;
int timeout2 = 500;
int timeout3 = 200;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
}

void loop() {
  if(millis() - previousAction1 >= timeout1) {
    ledState1 = 1 - ledState1;
    digitalWrite(13, ledState1);
    previousAction1 = millis();
  }

  if(millis() - previousAction2 >= timeout2) {
    ledState2 = 1 - ledState2;
    digitalWrite(13, ledState2);
    previousAction2 = millis();
  }

  if(millis() - previousAction3 >= timeout3) {
    ledState3 = 1 - ledState3;
    digitalWrite(13, ledState3);
    previousAction3 = millis();
  }
}