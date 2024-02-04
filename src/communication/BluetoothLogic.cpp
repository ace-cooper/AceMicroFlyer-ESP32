#include "BluetoothLogic.h"

void BluetoothLogic::init(DataReceivedCallback callback) {
    this->onDataReceived = callback;
 
    BLEDevice::init("AceMicroFlyer");

    BLEServer * pServer = BLEDevice::createServer();

    BLEService * pService = pServer->createService("123abc45-6789-0123-4567-89abcdef0000");

    BLECharacteristic * _pCharacteristic = pService->createCharacteristic (
        "beb5483e-36e1-4688-b7f5-ea07361b26a8",
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );

    this->pCharacteristic = _pCharacteristic;
    // pCharacteristic->setCallbacks(new BluetoothCallback(callback));

    // BLECharacteristic->setValue("Olá Mundo");

    pService->start();

    BLEAdvertising * pAdvertising = pServer->getAdvertising();

    pAdvertising->start();
}

void BluetoothLogic::loop() {
   std::string value = this->pCharacteristic->getValue();
   if (value.length() > 0) {
    //    CommunicationData data;
    //    data.action = value[0];
    //    data.value = atof(value.substr(1).c_str());
    //    if(onDataReceived != nullptr) {
    //        onDataReceived(data);
    //    }
   }
}
