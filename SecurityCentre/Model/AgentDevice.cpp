#include "AgentDevice.h"

AgentDevice::AgentDevice(int _id) : ElectronicDevice(_id) {}

std::optional<std::string> AgentDevice::convertToString(const std::any &value)
{
    try {
        if (value.type() == typeid(const char*)) {
            return std::string(std::any_cast<const char*>(value));
        }
        else if (value.type() == typeid(std::string)) {
            return std::any_cast<std::string>(value);
        }
        else if (value.type() == typeid(int)) {
            return std::to_string(std::any_cast<int>(value));
        }
        else if (value.type() == typeid(long)) {
            return std::to_string(std::any_cast<long>(value));
        }
        else {
            return std::nullopt;
        }
    } catch (const std::bad_any_cast&) {
        return std::nullopt;
    }
}
