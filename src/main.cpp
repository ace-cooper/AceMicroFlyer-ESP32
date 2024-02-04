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
    motorA.setPower(20);
    Serial.println("Motor A power set to: 20");
    delay(5000); 
    motorA.setPower(0);
    motorB.setPower(20);
    Serial.println("Motor B power set to: 20");
    delay(5000); 
    motorB.setPower(0);
    motorC.setPower(20);
    Serial.println("Motor C power set to: 20");
    delay(5000); 
    motorC.setPower(0);
    motorD.setPower(20);
    Serial.println("Motor D power set to: 20");
    delay(5000);
    motorA.setPower(40);
    motorB.setPower(40);
    motorC.setPower(40);
    motorD.setPower(40);
    Serial.println("All motors power set to: 40");
    delay(5000);
    motorA.setPower(0);
    motorB.setPower(0);
    motorC.setPower(0);
    motorD.setPower(0);
}