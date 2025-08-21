#include "facialrecognitionagent.h"
#include "Enum/accessresult.h"
#include "ElectronicDevice.h"

FacialRecognitionAgent::FacialRecognitionAgent(int _id, std::unique_ptr<IValidData> _validFacials) : AgentDevice(_id), validFacials(std::move(_validFacials)) {}

AccessResult FacialRecognitionAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        addLog("Access: GRANTED | Agent in status: OFF");
        return AccessResult::GRANTED;
    }
    else {
        auto match = validFacials->matches(credentials);
        if (match) {
            addLog(std::format("Access: GRANTED for Credentials: {}", convertToString(credentials).value()));
            emit facialAccessGranted();
        }
        else {
            addLog(std::format("Access: DENIED for Credentials: {}", convertToString(credentials).value()));
            emit facialAccessDenied();
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
