#include "FacialRecognitionAgent.h"
#include "Enum/AccessResult.h"
#include "ElectronicDevice.h"

FacialRecognitionAgent::FacialRecognitionAgent(int _id, std::unique_ptr<IValidData> _validFacials) : AgentDevice(_id), validFacials(std::move(_validFacials)) {}

AccessResult FacialRecognitionAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        addLog("Access: GRANTED | Agent in status: OFF");
        emit accessGranted(getId());
        return AccessResult::GRANTED;
    }
    else {
        auto match = validFacials->matches(credentials);
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
