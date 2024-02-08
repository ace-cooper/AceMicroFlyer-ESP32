#include <Arduino.h>
#include "motor/MotorController.h"
#include "communication/CommunicationController.h"
// #include "flight/FlightController.h"

MotorController motorA(5); 
MotorController motorB(6);
MotorController motorC(7);
MotorController motorD(8);

CommunicationController communication("BLUETOOTH");

// FlightController flightController(&motorA, &motorB, &motorC, &motorD);

void onDataReceived(CommunicationData data) {

    int motorPower[4];
    int i = 0;
    for (char power : data.value) {
      motorPower[i] = String(power).toInt();
      i++;
    }

    Serial.print("Motor Power: ");
    Serial.print(motorPower[0]);
    Serial.print(", ");
    Serial.print(motorPower[1]);
    Serial.print(", ");
    Serial.print(motorPower[2]);
    Serial.print(", ");
    Serial.println(motorPower[3]);
    
    motorA.setPower(motorPower[0]);
    motorB.setPower(motorPower[1]);
    motorC.setPower(motorPower[2]);
    motorD.setPower(motorPower[3]);


}

void setup() {
  Serial.begin(115200);

  communication.init(onDataReceived);
  // flightController.init();
}

void loop() {
    
    communication.loop();
    // flightController.loop();
    Serial.println("Loop");
    delay(50);
}