#ifndef RFIDAGENT_H
#define RFIDAGENT_H

#include "agentdevice.h"
#include "validdata.h"

template<typename T>
class RFIDAgent : public AgentDevice<T>
{
private:
    ValidData<T> validRFIDs;

public:
    RFIDAgent(int _id, const ValidData<T> &_validRFIDs);
    AccessResult verifyAccess(T credentials) override;
};

#endif // RFIDAGENT_H
