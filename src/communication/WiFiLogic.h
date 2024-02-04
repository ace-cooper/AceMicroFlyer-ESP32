#include "CommunicationLogicInterface.h"
 

class WiFiLogic : public CommunicationLogicInterface {
private:
    DataReceivedCallback onDataReceived;
    int motorPower[4] = {0,0,0,0};
public:
    void init(DataReceivedCallback callback) override;
    void loop() override;
    WiFiLogic();
    void handleRoot();
    void handleChangePower();
};
