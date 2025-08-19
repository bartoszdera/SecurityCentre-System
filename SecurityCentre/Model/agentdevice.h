#ifndef AGENTDEVICE_H
#define AGENTDEVICE_H

#include "electronicdevice.h"
#include "Enum/accessresult.h"

template<typename T>
class AgentDevice : public ElectronicDevice
{
public:
    AgentDevice(int _id);
    virtual AccessResult verifyAccess(T credentials) = 0;
};

template<typename T>
AgentDevice<T>::AgentDevice(int _id) : ElectronicDevice(_id) {}

#endif // AGENTDEVICE_H
