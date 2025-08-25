#include "DetectorDevice.h"
#include "ElectronicDevice.h"

DetectorDevice::DetectorDevice(int _id) : ElectronicDevice(_id)
{}

void DetectorDevice::registerSignal()
{
    if(getStatus() == ElectronicDevice::DeviceStatus::ON) {
        addLog("Signal registered.");
        emit signalRegistered(getId());
    }
}

