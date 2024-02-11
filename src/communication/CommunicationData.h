#ifndef CommunicationData_h
#define CommunicationData_h

#include <Arduino.h>

struct CommunicationData {
    unsigned long timestamp;
    String action;
    String value;
};

#endif
