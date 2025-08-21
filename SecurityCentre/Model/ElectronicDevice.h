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
    ElectronicDevice(int _id);
    void setStatus(DeviceStatus _status);
    void toggleStatus();
    int getId() const;
    std::vector<std::string> getLogs() const;
    DeviceStatus getStatus();

private:
    const int id;
    std::vector<std::string> logs;
    DeviceStatus status;
    std::string getTimestamp();

protected:
    std::string to_string(DeviceStatus _status);
    void addLog(std::string _log);

signals:
    void newLogAdded();

};

#endif // ELECTRONICDEVICE_H
