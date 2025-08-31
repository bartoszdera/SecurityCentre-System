#include "FingerprintAgent.h"
#include "IValidData.h"
#include <memory>

FingerprintAgent::FingerprintAgent(int _id, std::unique_ptr<IValidData> _validFingerprints) : AgentDevice(_id), validFingerprints(std::move(_validFingerprints)) {}

AccessResult FingerprintAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        addLog("Access: GRANTED | Agent in status: OFF");
        emit accessGranted(getId());
        return AccessResult::GRANTED;
    }
    else {
        auto match = validFingerprints->matches(credentials);
        if (match) {
            addLog(std::format("Access: GRANTED for Credentials: {}", convertToString(credentials).value()));
            emit accessGranted(getId());
        }
        else {
            addLog(std::format("Access: DENIED for Credentials: {}", convertToString(credentials).value()));
            emit accessDenied(getId());
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
