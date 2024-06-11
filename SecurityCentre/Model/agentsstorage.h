#include "agent.h"
#include <vector>

#ifndef AGENTSSTORAGE_H
#define AGENTSSTORAGE_H

class AgentsStorage
{
public:
    AgentsStorage();
    Agent addAgent(int id);
    Agent addAgent(int id, std::string desc);
    Agent::EAgentState turnOffAgent(int agentId);
    Agent::EAgentState turnOnAgent(int agentId);
    Agent::EAgentAccessResult verifyAccess(int agentId, std::string authData);
    std::string getAgentInfo(int agentId);
    Agent::EAgentState getAgentsStatus(int agentId);
    std::vector<Agent::AuthLog> getAgentsLogs(int agentId);
    inline std::vector<Agent> agentList() { return this->agentList_; }

private:
    std::vector<Agent> agentList_;
};

#endif // AGENTSSTORAGE_H
