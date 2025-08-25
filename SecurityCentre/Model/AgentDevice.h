#ifndef AGENTDEVICE_H
#define AGENTDEVICE_H

#include "ElectronicDevice.h"
#include "Enum/accessresult.h"
#include <any>
#include <qtmetamacros.h>

class AgentDevice : public ElectronicDevice
{
    Q_OBJECT
public:
    AgentDevice(int _id);
    virtual ~AgentDevice() = default;

    virtual AccessResult verifyAccess(const std::any& credentials) = 0;

protected:
    std::optional<std::string> convertToString(const std::any& value);

signals:
    void accessGranted(int deviceId);
    void accessDenied(int deviceId);
};

#endif // AGENTDEVICE_H
