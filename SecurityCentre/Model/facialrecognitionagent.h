#include "agent.h"
#include"Valid/validfacial.h"

#ifndef FACIALRECOGNITIONAGENT_H
#define FACIALRECOGNITIONAGENT_H

class FacialRecognitionAgent : public Agent
{
public:
    FacialRecognitionAgent(int id);
    FacialRecognitionAgent(int id, std::string desc);
    Agent::EAgentAccessResult VerifyAccess(std::string authenticationData);

private:
    ValidFacial validFacial;
};

#endif // FACIALRECOGNITIONAGENT_H
