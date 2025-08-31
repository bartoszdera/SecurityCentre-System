#ifndef DEVICESTORAGE_H
#define DEVICESTORAGE_H

#include "ElectronicDevice.h"
#include <vector>

/*!
 * DeviceStorage class that collects ElectronicDevice objects.
 */
class DeviceStorage
{
private:
    std::vector<std::shared_ptr<ElectronicDevice>> devices;
public:
    //! A default constructor
    DeviceStorage();

    //! A constructor
    /*!
     * \param initialDevices A vector of shared pointers to ElectronicDevice objects
     */
    DeviceStorage(std::vector<std::shared_ptr<ElectronicDevice>> initialDevices);

    /*!
     * Method to return a vector of shared pointers to ElectronicDevice objects.
     * \return A vector of shared pointers to stored ElectronicDevice objects
     */
    std::vector<std::shared_ptr<ElectronicDevice>> getDevices() const;

    /*!
     * Method to get a device by its identifier.
     * \param id An integer representing the identifier of the device
     * \return A shared pointer to the ElectronicDevice object with the specified id, or nullptr if not found
     */
    std::shared_ptr<ElectronicDevice> getDeviceById(int id) const;

    /*!
     * Method to add a device to the storage.
     * \param device A shared pointer to the ElectronicDevice object to be added
     */
    void addDevice(std::shared_ptr<ElectronicDevice> device);
};

#endif // DEVICESTORAGE_H
