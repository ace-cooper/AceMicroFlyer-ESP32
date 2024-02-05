#ifndef BluetoothCommunication_h
#define BluetoothCommunication_h

#include "CommunicationLogicInterface.h"
#include "CommunicationData.h"

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

class BluetoothLogic : public CommunicationLogicInterface {
private:
  
    DataReceivedCallback onDataReceived = nullptr;
    BLECharacteristic * pCharacteristic = nullptr;
public:
    void init(DataReceivedCallback callback) override;
    void loop() override;
};

#endif
