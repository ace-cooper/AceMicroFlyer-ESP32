#include "WiFiLogic.h"

void WiFiLogic::init(DataReceivedCallback callback) {
    this->onDataReceived = callback;
    // TODO
}

void WiFiLogic::loop() {
    // TODO
    CommunicationData data;
    
    onDataReceived(data);
}
