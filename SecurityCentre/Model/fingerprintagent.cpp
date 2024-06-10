#include "fingerprintagent.h"

FingerprintAgent::FingerprintAgent(int id) : Agent(id) {}

FingerprintAgent::FingerprintAgent(int id, std::string desc) : Agent(id, desc) {}

Agent::EAgentAccessResult FingerprintAgent::VerifyAccess(std::string authenticationData)
{
    if(Agent::state() == Agent::EAgentState::kOff){
        return Agent::EAgentAccessResult::kOmmitted;
    }

    for(auto &elem : validFingerprint.validFingerprints()){
        if(authenticationData == elem){
            return Agent::EAgentAccessResult::kGranted;
        }
    }

    return Agent::EAgentAccessResult::kDenied;
}
