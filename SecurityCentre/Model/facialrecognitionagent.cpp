// #include "facialrecognitionagent.h"
// #include "Enum/accessresult.h"
// #include "electronicdevice.h"

// template<typename T>
// FacialRecognitionAgent<T>::FacialRecognitionAgent(int _id, const ValidData<T> &_validFacials) : AgentDevice<T>(_id), validFacials(_validFacials) {}

// template<typename T>
// AccessResult FacialRecognitionAgent<T>::verifyAccess(T credentials)
// {
//     if (this->getStatus() == ElectronicDevice::DeviceStatus::OFF) {
//         return AccessResult::GRANTED;
//     }
//     else {
//         auto result = validFacials.matches(credentials) ? AccessResult::GRANTED : AccessResult::DENIED;
//         if (result == AccessResult::GRANTED) {
//             emit facialAccessGranted();
//         }
//         else {
//             emit facialAccessDenied();
//         }
//         return result;
//     }
// }
