#ifndef ELECTRONICDEVICE_H
#define ELECTRONICDEVICE_H

#include <qobject.h>
#include <qtmetamacros.h>
#include <string>
#include <vector>

class ElectronicDevice : public QObject
{
    Q_OBJECT

public:
    enum class DeviceStatus{ OFF=0, ON=1 };

private:
    const int id;
    std::vector<std::string> logs;
    DeviceStatus status;

public:
    ElectronicDevice(int _id);
    int getId() const;
    void addLog(std::string log);
    std::vector<std::string> getLogs() const;
    void setStatus(DeviceStatus _status);
    DeviceStatus getStatus();
    void toggleStatus();
};

#endif // ELECTRONICDEVICE_H
