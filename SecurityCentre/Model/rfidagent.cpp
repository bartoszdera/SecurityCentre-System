#include "rfidagent.h"

RFIDAgent::RFIDAgent(int id) : Agent(id) {}

RFIDAgent::RFIDAgent(int id, std::string desc) : Agent(id, desc) {}

Agent::EAgentAccessResult RFIDAgent::VerifyAccess(std::string authenticationData)
{
    if(Agent::state() == Agent::EAgentState::kOff){
        return Agent::EAgentAccessResult::kOmmitted;
    }

    for(auto &elem : validRfid.validRfids()){
        if(authenticationData == elem){
            return Agent::EAgentAccessResult::kGranted;
        }
    }

    return Agent::EAgentAccessResult::kDenied;
}
