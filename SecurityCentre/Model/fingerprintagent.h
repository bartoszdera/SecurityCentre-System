#ifndef FINGERPRINTAGENT_H
#define FINGERPRINTAGENT_H

#include "agentdevice.h"
#include "validdata.h"

template<typename T>
class FingerprintAgent : public AgentDevice<T>
{
private:
    ValidData<T> validFingerprints;

public:
    FingerprintAgent(int _id, const ValidData<T> &_validFingerprints);
    AccessResult verifyAccess(T credentials) override;
};

#endif // FINGERPRINTAGENT_H
