#include "facialrecognitionagent.h"

FacialRecognitionAgent::FacialRecognitionAgent(int id) : Agent(id) {}

FacialRecognitionAgent::FacialRecognitionAgent(int id, std::string desc) : Agent(id, desc) {}

Agent::EAgentAccessResult FacialRecognitionAgent::VerifyAccess(std::string authenticationData)
{
    if(Agent::state() == Agent::EAgentState::kOff){
        return Agent::EAgentAccessResult::kOmmitted;
    }

    for(auto &elem : validFacial.validFacials()){
        if(authenticationData == elem){
            return Agent::EAgentAccessResult::kGranted;
        }
    }

    return Agent::EAgentAccessResult::kDenied;
}
