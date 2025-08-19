#include "facialrecognitionagent.h"
#include "Enum/accessresult.h"
#include "electronicdevice.h"

FacialRecognitionAgent::FacialRecognitionAgent(int _id, std::unique_ptr<IValidData> _validFacials) : AgentDevice(_id), validFacials(std::move(_validFacials)) {}

AccessResult FacialRecognitionAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        return AccessResult::GRANTED;
    }
    else {
        auto match = validFacials->matches(credentials);
        if (match) {
            emit facialAccessGranted();
        }
        else {
            emit facialAccessDenied();
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
