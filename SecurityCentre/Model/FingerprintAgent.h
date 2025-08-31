#ifndef FINGERPRINTAGENT_H
#define FINGERPRINTAGENT_H

#include "IValidData.h"
#include "AgentDevice.h"
#include <memory>
#include <qtmetamacros.h>

/*!
 * FingerprintAgent class implementing methods and attributes specific to fingerprint agents.
 */
class FingerprintAgent : public AgentDevice
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \param _id An integer representing the identifier of the fingerprint agent
     * \param _validFingerprints A unique pointer to an IValidData object containing valid fingerprint data
     */
    FingerprintAgent(int _id, std::unique_ptr<IValidData> _validFingerprints);

    /*!
     * Method to verify access based on provided fingerprint credentials.
     * \param credentials An object of type std::any containing the fingerprint credentials to be verified
     */
    AccessResult verifyAccess(const std::any& credentials) override;

private:
    std::unique_ptr<IValidData> validFingerprints;
};

#endif // FINGERPRINTAGENT_H
