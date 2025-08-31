#ifndef DETECTORDEVICE_H
#define DETECTORDEVICE_H

#include "ElectronicDevice.h"
#include <qtmetamacros.h>

/*!
 * DetectorDevice class implementing methods and attributes specific to detector devices.
 */
class DetectorDevice : public ElectronicDevice
{
    Q_OBJECT
public:
    //! A constructor
    /*!
     * \param _id An integer representing the identifier of the detector device
     */
    DetectorDevice(int _id);

    /*!
     * Method to register a signal from the detector device.
     */
    void registerSignal();

signals:
    void signalRegistered(int deviceId);
};

#endif // DETECTORDEVICE_H
