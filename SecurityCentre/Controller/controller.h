#include"../Model/agentsstorage.h"
#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    bool addAgent();
    bool addAgent(std::string desc);
    bool turnOffAgent(int agentId);
    bool turnOnAgent(int agentId);
    std::string verifyAccess(int agentId, std::string authData);
    std::string getAgentInfo(int agentId);
    bool getAgentsStatus(int agentId);
    std::vector<std::string> getAgentsLogs(int agentId);

private:
    AgentsStorage agentsStorage;
    void createExampleAgent();
};

#endif // CONTROLLER_H
