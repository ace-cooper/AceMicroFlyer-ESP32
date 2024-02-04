#ifndef CommunicationController_h
#define CommunicationController_h

#include "Arduino.h"
#include "CommunicationData.h"
#include "CommunicationLogicInterface.h"

typedef void (*DataReceivedCallback)(CommunicationData);

class CommunicationController {
  public:
    CommunicationController(String _mode); 
    void init(DataReceivedCallback callback);
    void loop();
  private:
    String mode;
    CommunicationLogicInterface* communication;
};

#endif
