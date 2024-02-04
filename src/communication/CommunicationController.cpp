#include "CommunicationController.h"
#include "WiFiLogic.h" 
// #include "BluetoothLogic.h" 

CommunicationController::CommunicationController(String _mode) {
    mode = _mode;
    communication = nullptr; 
}

void CommunicationController::init(DataReceivedCallback callback) {

    if (String(mode) == "WIFI") {
        communication = new WiFiLogic();
    } else if (String(mode) == "BLUETOOTH") {
        // communication = new BluetoothLogic();
    }

    if (communication != nullptr) {
        communication->init(callback);
    }
}

void CommunicationController::loop() {
    if (communication != nullptr) {
        communication->loop();
    }
}
