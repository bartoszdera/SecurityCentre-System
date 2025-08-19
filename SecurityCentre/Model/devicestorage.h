#ifndef DEVICESTORAGE_H
#define DEVICESTORAGE_H

#include "electronicdevice.h"
#include <vector>

class DeviceStorage
{
private:
    std::vector<std::shared_ptr<ElectronicDevice>> devices;
public:
    DeviceStorage();
    DeviceStorage(std::vector<std::shared_ptr<ElectronicDevice>> initialDevices);
    std::vector<std::shared_ptr<ElectronicDevice>> getDevices() const;
    std::shared_ptr<ElectronicDevice> getDeviceById(int id) const;
    void addDevice(std::shared_ptr<ElectronicDevice> device);
};

#endif // DEVICESTORAGE_H
