#include <Arduino.h>
#include "motor/MotorController.h"
#include "communication/CommunicationController.h"
// #include "flight/FlightController.h"

MotorController motorFL(5); 
MotorController motorFR(6);
MotorController motorBL(7);
MotorController motorBR(8);

CommunicationController communication("BLUETOOTH");

// FlightController flightController(&motorFL, &motorFR, &motorBL, &motorBR);

void onDataReceived(CommunicationData data) {

        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);

        delay(3000);

        digitalWrite(2, LOW);
        digitalWrite(4, LOW);
    // int motorPower[4];
    // int i = 0;
    // for (char power : data.value) {
    //   motorPower[i] = String(power).toInt();
    //   i++;
    // }

    // Serial.print("Motor Power: ");
    // Serial.print(motorPower[0]);
    // Serial.print(", ");
    // Serial.print(motorPower[1]);
    // Serial.print(", ");
    // Serial.print(motorPower[2]);
    // Serial.print(", ");
    // Serial.println(motorPower[3]);
    
    
    // motorFL.setPower(motorPower[0]);
    // motorFR.setPower(motorPower[1]);
    // motorBL.setPower(motorPower[2]);
    // motorBR.setPower(motorPower[3]);


}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  communication.init(onDataReceived);
  // flightController.init();
}

void loop() {
    
    communication.loop();
    // flightController.loop();
    Serial.println("Loop");
    delay(50);
}