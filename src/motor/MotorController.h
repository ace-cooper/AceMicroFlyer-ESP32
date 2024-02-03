#ifndef MotorController_h
#define MotorController_h

#include "Arduino.h"

class MotorController {
  public:
    MotorController(int pin); 
    void setPower(int power);
  private:
    int _pin;
};

#endif
