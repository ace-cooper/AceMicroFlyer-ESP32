#include "BluetoothLogic.h"
#include <string>


static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

std::string base64_decode(std::string const& encoded_string) {
    size_t in_len = encoded_string.size();
    size_t i = 0;
    size_t j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && ( encoded_string[in_] != '=') && isalnum(encoded_string[in_]) || (encoded_string[in_] == '+') || (encoded_string[in_] == '/')) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;

        for (j = 0; j <4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}


class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
        BLEDevice::stopAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      BLEDevice::startAdvertising();
    }
};

void BluetoothLogic::init(DataReceivedCallback callback) {
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);

    this->onDataReceived = callback;
 
    BLEDevice::init("AceMicroFlyer");

    BLEServer * pServer = BLEDevice::createServer();
    pServer->setCallbacks(new ServerCallbacks());

    BLEService * pService = pServer->createService("123abc45-6789-0123-4567-89abcdef0000");

    BLECharacteristic * _pCharacteristic = pService->createCharacteristic (
        "beb5483e-36e1-4688-b7f5-ea07361b26a8",
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );

    this->pCharacteristic = _pCharacteristic;

    pService->start();

    BLEAdvertising * pAdvertising = pServer->getAdvertising();

    pAdvertising->start();
}

bool led = LOW;
void BluetoothLogic::loop() {
    digitalWrite(2, led);
    digitalWrite(4, !led);
    led = !led;
    delay(350);
   std::string value = this->pCharacteristic->getValue();
   if (value.length() > 0) {
    value = base64_decode(value);
    this->pCharacteristic->setValue("");
    for (int i = 0; i < 3; i++) {
        digitalWrite(2, led);
        digitalWrite(4, led);
        led = !led;
        delay(200);
    }
     if (value == "1") {
        digitalWrite(2, HIGH);
        digitalWrite(4, HIGH);
     } else if (value == "2") {
        digitalWrite(2, LOW);
        digitalWrite(4, LOW);
     } else if (value == "3") {
        digitalWrite(2, HIGH);
        digitalWrite(4, LOW);
     } else if (value == "4") {
        digitalWrite(2, LOW);
        digitalWrite(4, HIGH);
     } 
     delay(2500);
    //    CommunicationData data;
    //    data.action = value[0];
    //    data.value = atof(value.substr(1).c_str());
    //    if(onDataReceived != nullptr) {
    //        onDataReceived(data);
    //    }
   }
}
