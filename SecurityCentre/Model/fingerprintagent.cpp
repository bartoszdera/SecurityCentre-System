#include "fingerprintagent.h"
#include "IValidData.h"
#include <memory>

FingerprintAgent::FingerprintAgent(int _id, std::unique_ptr<IValidData> _validFingerprints) : AgentDevice(_id), validFingerprints(std::move(_validFingerprints)) {}

AccessResult FingerprintAgent::verifyAccess(const std::any& credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        return AccessResult::GRANTED;
    }
    else {
        auto match = validFingerprints->matches(credentials);
        if (match) {
            emit fingerprintAccessGranted();
        }
        else {
            emit fingerprintAccessDenied();
        }
        return match ? AccessResult::GRANTED : AccessResult::DENIED;
    }
}
