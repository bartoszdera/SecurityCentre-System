#include <qobject.h>
#include <qtmetamacros.h>
#include<string>
#include<vector>
#include<ctime>

#ifndef AGENT_H
#define AGENT_H

class Agent : public QObject
{
    Q_OBJECT
// MEMBERS DECLARATIONS
public:
    enum class EAgentState
    {
        kOff=0,
        kOn=1,
    };

    enum class EAgentAccessResult
    {
        kDenied=0,
        kGranted=1,
        kOmmitted=2,
    };

    class AuthLog{
        std::time_t timestamp_;
        std::string authData_;
        EAgentAccessResult result_;

    public:
        AuthLog(std::time_t timestamp, std::string authData, EAgentAccessResult result);
        std::string getAuthLog();
    };

public slots:
    void changeState();

signals:
    void agentCreated(int id_, bool boolState, std::string description_, std::vector<Agent::AuthLog> logs_);
    void stateChanged(bool boolState);

private:
    int id_;
    EAgentState state_;
    std::string description_;
    std::vector<AuthLog> logs_;


// METHODS DECLARATIONS
public:
    Agent(int id);
    Agent(int id, std::string desc);
    inline std::string description() { return this->description_; }
    inline EAgentState state() { return this->state_; }
    EAgentState setState(EAgentState state);
    inline std::vector<AuthLog> logs() { return this->logs_; }
    virtual EAgentAccessResult VerifyAccess(std::string authenticationData){ return EAgentAccessResult::kDenied; }

private:
    void add_log(std::time_t timestamp, std::string authData, EAgentAccessResult result);
    static std::string enumAccessToString(EAgentAccessResult result);
};

#endif // AGENT_H
