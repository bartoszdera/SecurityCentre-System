#ifndef DETECTORDEVICE_H
#define DETECTORDEVICE_H

#include "ElectronicDevice.h"
#include <qtmetamacros.h>

class DetectorDevice : public ElectronicDevice
{
    Q_OBJECT
public:
    DetectorDevice(int _id);

    void registerSignal();

signals:
    void signalRegistered();
};

#endif // DETECTORDEVICE_H
