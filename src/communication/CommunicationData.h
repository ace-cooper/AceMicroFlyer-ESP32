#ifndef CommunicationData_h
#define CommunicationData_h

struct CommunicationData {
    unsigned long timestamp;
    char action[10];
    float value;
};

#endif
