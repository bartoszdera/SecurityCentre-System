#ifndef RFIDAGENT_H
#define RFIDAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

class RFIDAgent : public AgentDevice
{
    Q_OBJECT

private:
    std::unique_ptr<IValidData> validRFIDs;

public:
    RFIDAgent(int _id, std::unique_ptr<IValidData> _validRFIDs);
    AccessResult verifyAccess(const std::any& credentials) override;
};

#endif // RFIDAGENT_H
