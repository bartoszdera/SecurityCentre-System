#include "ElectronicDevice.h"

#include <format>

ElectronicDevice::ElectronicDevice(int _id) : id(_id)
{
    status = DeviceStatus::ON;
}

int ElectronicDevice::getId() const
{
    return id;
}

void ElectronicDevice::addLog(std::string _log)
{
    auto timestamp = 0;
    logs.push_back(std::format("{} | {}", getTimestamp(), _log));

    emit newLogAdded();
}

std::vector<std::string> ElectronicDevice::getLogs() const
{
    return logs;
}

std::string ElectronicDevice::to_string(DeviceStatus _status)
{
    switch (status) {
        case DeviceStatus::ON: return "ON";
        case DeviceStatus::OFF: return "OFF";
        default: return "UNKNOWN";
    }
}

std::string ElectronicDevice::getTimestamp()
{
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm localTime = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void ElectronicDevice::setStatus(DeviceStatus _status)
{
    status = _status;
}

ElectronicDevice::DeviceStatus ElectronicDevice::getStatus()
{
    return status;
}

void ElectronicDevice::toggleStatus()
{
    status = (status == DeviceStatus::ON) ? DeviceStatus::OFF : DeviceStatus::ON;
    addLog(std::format("Status changed to: {}", to_string(status)));
}
