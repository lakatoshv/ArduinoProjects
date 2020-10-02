#include "SevSeg.h"
SevSeg sevseg; 

int number = 0;

#define joyX A0
#define joyY A1

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {6, 5, 2, 3, 4, 7, 8, 9};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
}

void loop(){
    displayDigit(4);       
}

void useJoystic() {
    // put your main code here, to run repeatedly:
    int xValue = analogRead(joyX);
    int yValue = analogRead(joyY);

    //print the values with to plot or view    
    if((xValue == 0 || yValue == 0) && number > 0){
        number--;
        displayDigit(number);
    }
    if((xValue == 1023 || yValue == 1023) && number < 9){
        number++;   
        displayDigit(number);
    }
}

void displayDigit(int number) {
    sevseg.setNumber(number);
    delay(1000);
    sevseg.refreshDisplay();
}