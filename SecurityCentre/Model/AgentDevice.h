#ifndef AGENTDEVICE_H
#define AGENTDEVICE_H

#include "ElectronicDevice.h"
#include "Enum/AccessResult.h"
#include <any>
#include <qtmetamacros.h>

/*!
 * AgentDevice class is an abstract class representing devices that can verify access credentials.
 */
class AgentDevice : public ElectronicDevice
{
    Q_OBJECT
public:
    //! A constructor
    /*!
     * \param _id An integer representing the identifier of the device
     */
    AgentDevice(int _id);

    /*!
     * Virtual method to implement access credentials way of verifiaction.
     * \param credentials An object of type std::any representing the credentials to be verified
     * \return An AccessResult enum value representing the result of the access verification
     */
    virtual AccessResult verifyAccess(const std::any& credentials) = 0;

protected:
    /*!
     * Helper method to convert std::any to std::string if possible.
     * \param value An object of type std::any to be converted
     * \return An optional string containing the converted value, or std::nullopt if conversion fails
     */
    std::optional<std::string> convertToString(const std::any& value);

signals:
    void accessGranted(int deviceId);
    void accessDenied(int deviceId);
};

#endif // AGENTDEVICE_H
