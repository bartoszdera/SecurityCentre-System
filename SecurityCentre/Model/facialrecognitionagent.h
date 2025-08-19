#ifndef FACIALRECOGNITIONAGENT_H
#define FACIALRECOGNITIONAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

class FacialRecognitionAgent : public AgentDevice
{
    Q_OBJECT

private:
    std::unique_ptr<IValidData> validFacials;

public:
    FacialRecognitionAgent(int _id, std::unique_ptr<IValidData> _validFacials);
    AccessResult verifyAccess(const std::any& credentials) override;

signals:
    void facialAccessGranted();
    void facialAccessDenied();
};

#endif // FACIALRECOGNITIONAGENT_H
