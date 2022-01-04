/// <summary>
/// Use motor driver module L298N.
/// </summary>
// <copyright file="motorDriver.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

//Define the interfaces
const int PIN_L1 = 8;
const int PIN_L2 = 9;
const int PIN_L3 = 6;
const int PIN_L4 = 7;

//Define the interfaces EA and EB (PWM speed control).
const int SPEED_PIN_EA = 11;
const int SPEED_PIN_EB = 10;

void setup()
{
  pinMode(PIN_L1,OUTPUT);
  pinMode(PIN_L2,OUTPUT);
  pinMode(PIN_L3,OUTPUT);
  pinMode(PIN_L4,OUTPUT);
  
  pinMode(SPEED_PIN_EA,OUTPUT);
  pinMode(SPEED_PIN_EB,OUTPUT);
}

void loop()
{
 //Go forward
     analogWrite(SPEED_PIN_EA,100);
     analogWrite(SPEED_PIN_EB,100);
     digitalWrite(PIN_L4,LOW);
     digitalWrite(PIN_L3,HIGH);
     digitalWrite(PIN_L1,LOW);
     digitalWrite(PIN_L2,HIGH);
     delay(2000);
 //Go back
     analogWrite(SPEED_PIN_EA,100);
     analogWrite(SPEED_PIN_EB,100);
     digitalWrite(PIN_L4,HIGH);
     digitalWrite(PIN_L3,LOW);
     digitalWrite(PIN_L1,HIGH);
     digitalWrite(PIN_L2,LOW);
     delay(2000);
 }