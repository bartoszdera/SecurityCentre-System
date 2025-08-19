#include "rfidagent.h"
#include "IValidData.h"
#include <memory>

RFIDAgent::RFIDAgent(int _id, std::unique_ptr<IValidData> _validRFIDs) : AgentDevice(_id), validRFIDs(std::move(_validRFIDs)) {}

AccessResult RFIDAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        return AccessResult::GRANTED;
    }
    else {
        auto match = validRFIDs->matches(credentials);
        if (match) {
            emit RFIDAccessGranted();
        }
        else {
            emit RFIDAccessDenied();
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
