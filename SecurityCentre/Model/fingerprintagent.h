#ifndef FINGERPRINTAGENT_H
#define FINGERPRINTAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

class FingerprintAgent : public AgentDevice
{
    Q_OBJECT

private:
    std::unique_ptr<IValidData> validFingerprints;

public:
    FingerprintAgent(int _id, std::unique_ptr<IValidData> _validFingerprints);
    AccessResult verifyAccess(const std::any& credentials) override;

signals:
    void fingerprintAccessGranted();
    void fingerprintAccessDenied();
};

#endif // FINGERPRINTAGENT_H
