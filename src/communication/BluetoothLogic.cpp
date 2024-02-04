#include "BluetoothLogic.h"

void BluetoothLogic::init(DataReceivedCallback callback) {
    this->onDataReceived = callback;
    // SerialBT.begin("AceMicroFlyer");
    BLEDevice::init("AceMicroFlyer");

    BLEServer * pServer = BLEDevice::createServer();

    BLEService * pService = pServer->createService("123abc45-6789-0123-4567-89abcdef0000");

    BLECharacteristic * pCharacteristic = pService->createCharacteristic (
        "beb5483e-36e1-4688-b7f5-ea07361b26a8",
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );

    // BLECharacteristic->setCallbacks (novo MyCallbacks());

    // BLECharacteristic->setValue("Olá Mundo");

    pService->start();

    BLEAdvertising * pAdvertising = pServer->getAdvertising();

    pAdvertising->start();
}

void BluetoothLogic::loop() {
    // if (SerialBT.available()) { 
    //     CommunicationData data;
    //     if (SerialBT.readBytes((char*)&data, sizeof(data)) == sizeof(data)) {
            
    //         onDataReceived(data);
    //     }
    // }
}
