#include "devicestorage.h"
#include "electronicdevice.h"
#include <memory>
#include <stdexcept>

DeviceStorage::DeviceStorage() {}

DeviceStorage::DeviceStorage(std::vector<std::shared_ptr<ElectronicDevice>> initialDevices)
    : devices(initialDevices) {}


std::vector<std::shared_ptr<ElectronicDevice>> DeviceStorage::getDevices() const {
    return devices;
}

std::shared_ptr<ElectronicDevice> DeviceStorage::getDeviceById(int id) const {
    for (const auto& device : devices) {
        if (device->getId() == id) {
            return device;
        }
    }
    throw std::runtime_error("Device o podanym ID nie istnieje!");
}

void DeviceStorage::addDevice(std::shared_ptr<ElectronicDevice> device)
{
    devices.push_back(device);
}
