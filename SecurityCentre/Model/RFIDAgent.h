#ifndef RFIDAGENT_H
#define RFIDAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

/*!
 * RFIDAgent class implementing methods and attributes specific to RFID agents.
 */
class RFIDAgent : public AgentDevice
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _id An integer representing the identifier of the RFID agent
     * \param _validRFIDs A unique pointer to an IValidData object containing valid RFID data
     */
    RFIDAgent(int _id, std::unique_ptr<IValidData> _validRFIDs);

    /*!
     * Method to verify access based on provided RFID credentials.
     * \param credentials An object of type std::any containing the RFID credentials to be verified
     */
    AccessResult verifyAccess(const std::any& credentials) override;

private:
    std::unique_ptr<IValidData> validRFIDs;
};

#endif // RFIDAGENT_H
