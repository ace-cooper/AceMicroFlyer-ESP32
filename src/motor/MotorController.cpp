#include "MotorController.h"

MotorController::MotorController(int pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

void MotorController::setPower(int power) {
  int pwmValue = map(power, 0, 100, 0, 1023);
  analogWrite(_pin, pwmValue);
}
