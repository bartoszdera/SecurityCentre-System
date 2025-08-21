#include "rfidagent.h"
#include "IValidData.h"
#include <memory>

RFIDAgent::RFIDAgent(int _id, std::unique_ptr<IValidData> _validRFIDs) : AgentDevice(_id), validRFIDs(std::move(_validRFIDs)) {}

AccessResult RFIDAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        addLog("Access: GRANTED | Agent in status: OFF");
        return AccessResult::GRANTED;
    }
    else {
        auto match = validRFIDs->matches(credentials);
        if (match) {
            addLog(std::format("Access: GRANTED for Credentials: {}", convertToString(credentials).value()));
            emit RFIDAccessGranted();
        }
        else {
            addLog(std::format("Access: DENIED for Credentials: {}", convertToString(credentials).value()));
            emit RFIDAccessDenied();
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
