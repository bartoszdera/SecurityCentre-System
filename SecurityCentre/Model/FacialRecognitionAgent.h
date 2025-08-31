#ifndef FACIALRECOGNITIONAGENT_H
#define FACIALRECOGNITIONAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

/*!
 * FacialRecognitionAgent class implementing methods and attributes specific to facial recognition agents.
 */
class FacialRecognitionAgent : public AgentDevice
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _id An integer representing the identifier of the facial recognition agent
     * \param _validFacials A unique pointer to an IValidData object containing valid facial data
     */
    FacialRecognitionAgent(int _id, std::unique_ptr<IValidData> _validFacials);

    /*!
     * Method to verify access based on provided RFID credentials.
     * \param credentials An object of type std::any containing the RFID credentials to be verified
     */
    AccessResult verifyAccess(const std::any& credentials) override;

private:
    std::unique_ptr<IValidData> validFacials;
};

#endif // FACIALRECOGNITIONAGENT_H
