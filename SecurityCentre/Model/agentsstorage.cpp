#include "agentsstorage.h"
#include <vector>

AgentsStorage::AgentsStorage() {
    agentList_ = std::vector<Agent>();
}

Agent AgentsStorage::addAgent(int id)
{
    Agent tempAgent = Agent(id);
    agentList_.push_back(tempAgent);

    return tempAgent;
}

Agent AgentsStorage::addAgent(int id, std::string desc)
{
    Agent tempAgent = Agent(id, desc);
    agentList_.push_back(tempAgent);

    return tempAgent;
}

Agent::EAgentState AgentsStorage::turnOffAgent(int agentId)
{
    return agentList_.at(agentId).setState(Agent::EAgentState::kOn);
}

Agent::EAgentAccessResult AgentsStorage::verifyAccess(int agentId, std::string authData)
{
    return agentList_.at(agentId).VerifyAccess(authData);
}

std::string AgentsStorage::getAgentInfo(int agentId)
{
    return agentList_.at(agentId).description();
}

Agent::EAgentState AgentsStorage::getAgentsStatus(int agentId)
{
    return agentList_.at(agentId).state();
}

std::vector<Agent::AuthLog> AgentsStorage::getAgentsLogs(int agentId)
{
    return agentList_.at(agentId).logs();
}


