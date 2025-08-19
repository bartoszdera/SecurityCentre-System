#include "electronicdevice.h"

ElectronicDevice::ElectronicDevice(int _id) : id(_id)
{
    status = DeviceStatus::ON;
}

int ElectronicDevice::getId() const
{
    return id;
}

void ElectronicDevice::addLog(std::string log)
{
    logs.push_back(log);
}

std::vector<std::string> ElectronicDevice::getLogs() const
{
    return logs;
}

void ElectronicDevice::setStatus(DeviceStatus _status)
{
    status = _status;
}

ElectronicDevice::DeviceStatus ElectronicDevice::getStatus()
{
    return status;
}
