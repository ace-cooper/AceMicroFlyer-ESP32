#include <Arduino.h>
#include "motor/MotorController.h"
#include "communication/CommunicationController.h"

MotorController motorA(5); 
MotorController motorB(6);
MotorController motorC(7);
MotorController motorD(8);

CommunicationController communication("WIFI");

void onDataReceived(CommunicationData data) {
    Serial.print("Dados Recebidos - Timestamp: ");
    Serial.print(data.timestamp);
    Serial.print(", Ação: ");
    Serial.print(data.action);
    Serial.print(", Valor: ");
    Serial.println(data.value);
    // split data.value by ':' and set the power of each motor and set 0 if the value is not present
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
    
    // motorA.setPower(motorPower[0]);
    // motorB.setPower(motorPower[1]);
    // motorC.setPower(motorPower[2]);
    // motorD.setPower(motorPower[3]);


}

void setup() {
  Serial.begin(115200);

  communication.init(onDataReceived);
}

void loop() {
    
    communication.loop();

    // motorA.setPower(20);
    // Serial.println("Motor A power set to: 20");
    // delay(5000); 
    // motorA.setPower(0);
    // motorB.setPower(20);
    // Serial.println("Motor B power set to: 20");
    // delay(5000); 
    // motorB.setPower(0);
    // motorC.setPower(20);
    // Serial.println("Motor C power set to: 20");
    // delay(5000); 
    // motorC.setPower(0);
    // motorD.setPower(20);
    // Serial.println("Motor D power set to: 20");
    // delay(5000);
    // motorA.setPower(40);
    // motorB.setPower(40);
    // motorC.setPower(40);
    // motorD.setPower(40);
    // Serial.println("All motors power set to: 40");
    // delay(5000);
    // motorA.setPower(0);
    // motorB.setPower(0);
    // motorC.setPower(0);
    // motorD.setPower(0);
}