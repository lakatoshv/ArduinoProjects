/// <summary>
/// Use temperature sensor to display temperature in celsius and fahrenheit.
/// </summary>
// <copyright file="temperatureSensor.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

const int TEMPERATURE_SENSOR_PIN = A1;

void setup()
{
  pinMode(TEMPERATURE_SENSOR_PIN,INPUT); // Configuring pin A1 as input
  Serial.begin(9600);
  delay(500);
}

void loop() 
{
  float temperature = (analogRead(TEMPERATURE_SENSOR_PIN) / 1024.0) * 5000;
  
  float celsius = temperature / 10;
  Serial.print("in Сelsius=");
  Serial.print("\t");
  Serial.print(celsius);
  Serial.println();
  
  float fahrenheit = (celsius * 9) / 5 + 32;
  Serial.print("in Fahrenheit=");
  Serial.print("\t");
  Serial.print(fahrenheit);
  Serial.println();
  delay(1000);
}