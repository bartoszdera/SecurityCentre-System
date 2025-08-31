#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include <qobject.h>
#include <qtmetamacros.h>
#include <string>
#include <vector>

/*!
 * ElectronicDevice class implementing methods and attributes common to all electronic devices.
 * This is the base class for all specific device types.
 */
class ElectronicDevice : public QObject
{
    Q_OBJECT

public:
    /*!
     * DeviceStatus enum representing the status of the device.
     */
    enum class DeviceStatus{
        OFF=0,
        ON=1
    };

    //! A constructor
    /*!
     * \param _id An integer representing the unique identifier of the device
     */
    ElectronicDevice(int _id);

    /*!
     * Method to get the identifier of the device.
     * \return An integer representing the identifier of the device
     */
    int getId() const;

    /*!
     * Method to set the status of the device.
     * \param _status A DeviceStatus enum value representing the new status of the device
     */
    void setStatus(DeviceStatus _status);

    /*!
     * Method to toggle the status of the device between ON and OFF.
     * It changes the status of the device to the opposite to the current status.
     */
    void toggleStatus();

    /*!
     * Method to get the current status of the device.
     * \return A DeviceStatus enum value representing the current status of the device
     */
    DeviceStatus getStatus();

    /*!
     * Method to convert a DeviceStatus enum value to its string representation.
     * \param _status A DeviceStatus enum value to be converted
     * \return A string representing the DeviceStatus enum value
     */
    std::string to_string(DeviceStatus _status);

    /*!
     * Method to get the logs of the device.
     * \return A vector of strings representing the logs of the device
     */
    std::vector<std::string> getLogs() const;

protected:
    /*!
     * Method to add a log entry to the device's logs.
     * Method pushes a new log entry to the logs vector and emits the newLogAdded signal.
     * \param _log A string representing the log entry to be added
     */
    void addLog(std::string _log);

private:
    const int id;
    std::vector<std::string> logs;
    DeviceStatus status;
    std::string getTimestamp();


signals:
    void newLogAdded();

};

#endif // ELECTRONICDEVICE_H
