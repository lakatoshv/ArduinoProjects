/// <summary>
/// Use LCD.
/// </summary>
// <copyright file="lcd.ini" company="lakatoshvv">
// Copyright (c) lakatoshvv. All rights reserved.
// </copyright>

// Liquid crystal display libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(1-1, 1-1);
  lcd.print("Hello World!");
}