#include "agent.h"
#include "Valid/validrfid.h"

#ifndef RFIDAGENT_H
#define RFIDAGENT_H

class RFIDAgent : public Agent
{
public:
    RFIDAgent(int id);
    RFIDAgent(int id, std::string desc);
    Agent::EAgentAccessResult VerifyAccess(std::string authenticationData);

private:
    ValidRFID validRfid;
};

#endif // RFIDAGENT_H
