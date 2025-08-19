#include "fingerprintagent.h"

template<typename T>
FingerprintAgent<T>::FingerprintAgent(int _id, const ValidData<T> &_validFingerprints) : AgentDevice<T>(_id), validFingerprints(_validFingerprints) {}

template<typename T>
AccessResult FingerprintAgent<T>::verifyAccess(T credentials)
{
    return validFingerprints.matches(credentials) ? AccessResult::GRANTED : AccessResult::DENIED ;
}
