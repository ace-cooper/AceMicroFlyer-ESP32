#ifndef CommunicationInterface_h
#define CommunicationInterface_h

#include "CommunicationData.h"

typedef void (*DataReceivedCallback)(CommunicationData);

class CommunicationLogicInterface {
public:
    virtual void init(DataReceivedCallback callback) = 0;
    virtual void loop() = 0;
};

#endif
