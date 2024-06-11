#include "agent.h"

Agent::Agent(int id)
{
    Agent(id, "Empty");
}

Agent::Agent(int id, std::string desc) : id_(id), description_(desc) {
    this->state_ = EAgentState::kOn;
    this->logs_ = std::vector<AuthLog>();
}

Agent::EAgentState Agent::setState(EAgentState state)
{
    this->state_ = state;
    // TODO: Don't like this solution.
    return this->state_;
}

void Agent::add_log(time_t timestamp, std::string authData, EAgentAccessResult result)
{
    auto log = Agent::AuthLog(timestamp, authData, result);
    this->logs_.push_back(log);
}

std::string Agent::enumAccessToString(EAgentAccessResult result)
{
    switch(result){
        case EAgentAccessResult::kDenied:
            return "DENIED";
            break;
        case EAgentAccessResult::kGranted:
            return "GRANTED";
            break;
        case EAgentAccessResult::kOmmitted:
            return "OMMITTED";
            break;
        default:
            return "RESULT NOT RECOGNIZED";
    }
}

Agent::AuthLog::AuthLog(time_t timestamp, std::string authData, EAgentAccessResult result): timestamp_(timestamp), authData_(authData), result_(result){}

std::string Agent::AuthLog::getAuthLog()
{
    return this->timestamp_ + " An authorization attempt was made.\nAutorization data: " + this->authData_ + "\nResult: " + enumAccessToString(this->result_);
}
