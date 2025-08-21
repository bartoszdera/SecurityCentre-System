#ifndef DETECTORDEVICE_H
#define DETECTORDEVICE_H

#include "ElectronicDevice.h"

class DetectorDevice : public ElectronicDevice
{
public:
    void registerSignal();
};

#endif // DETECTORDEVICE_H
