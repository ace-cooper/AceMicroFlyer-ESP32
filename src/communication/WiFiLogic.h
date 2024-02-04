#include "CommunicationLogicInterface.h"

class WiFiLogic : public CommunicationLogicInterface {
private:
    DataReceivedCallback onDataReceived;
public:
    void init(DataReceivedCallback callback) override;
    void loop() override;
};
