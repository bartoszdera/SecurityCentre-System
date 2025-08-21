#ifndef AGENTDEVICE_H
#define AGENTDEVICE_H

#include "ElectronicDevice.h"
#include "Enum/accessresult.h"
#include <any>

class AgentDevice : public ElectronicDevice
{
public:
    AgentDevice(int _id);
    virtual ~AgentDevice() = default;

    virtual AccessResult verifyAccess(const std::any& credentials) = 0;
};

#endif // AGENTDEVICE_H
