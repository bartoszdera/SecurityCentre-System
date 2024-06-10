#include "agent.h"
#include "Valid/validfingerprint.h"

#ifndef FINGERPRINTAGENT_H
#define FINGERPRINTAGENT_H

class FingerprintAgent : public Agent
{
public:
    FingerprintAgent(int id);
    FingerprintAgent(int id, std::string desc);
    Agent::EAgentAccessResult VerifyAccess(std::string authenticationData);

private:
    ValidFingerprint validFingerprint;
};

#endif // FINGERPRINTAGENT_H
