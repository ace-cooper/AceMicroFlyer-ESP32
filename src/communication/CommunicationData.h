#ifndef CommunicationData_h
#define CommunicationData_h

#include <Arduino.h> // Include the necessary header file for the String class

struct CommunicationData {
    unsigned long timestamp;
    char* action;
    String value;
};

#endif
