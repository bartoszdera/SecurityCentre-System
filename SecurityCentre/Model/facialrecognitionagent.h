#ifndef FACIALRECOGNITIONAGENT_H
#define FACIALRECOGNITIONAGENT_H

#include "agentdevice.h"
#include "validdata.h"

template<typename T>
class FacialRecognitionAgent : public AgentDevice<T>
{
    // MEMBERS
private:
    ValidData<T> validFacials;

    // METHODS
public:
    FacialRecognitionAgent(int _id, const ValidData<T> &_validFacials);
    AccessResult verifyAccess(T credentials) override;

signals:
    void facialAccessGranted();
    void facialAccessDenied();
};

template<typename T>
FacialRecognitionAgent<T>::FacialRecognitionAgent(int _id, const ValidData<T> &_validFacials) : AgentDevice<T>(_id), validFacials(_validFacials) {}

template<typename T>
AccessResult FacialRecognitionAgent<T>::verifyAccess(T credentials)
{
    if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
        return AccessResult::GRANTED;
    }
    else {
        auto result = validFacials.matches(credentials) ? AccessResult::GRANTED : AccessResult::DENIED;
        if (result == AccessResult::GRANTED) {
            emit facialAccessGranted();
        }
        else {
            emit facialAccessDenied();
        }
        return result;
    }
}

#endif // FACIALRECOGNITIONAGENT_H
