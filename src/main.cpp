#include <Arduino.h>
#include "motor/MotorController.h"

MotorController motorA(D5); 
MotorController motorB(D6);
MotorController motorC(D7);
MotorController motorD(D8);

void setup() {
  Serial.begin(115200);
}

void loop() {
    motorC.setPower(20);
    Serial.print("Motor power set to: ");
    Serial.println(20);
    delay(5000); 
    motorC.setPower(40);
    Serial.print("Motor power set to: ");
    Serial.println(40);
    delay(5000); 
    motorC.setPower(60);
    Serial.print("Motor power set to: ");
    Serial.println(60);
    delay(5000); 
    motorC.setPower(80);
    Serial.print("Motor power set to: ");
    Serial.println(80);
    delay(5000); 
}