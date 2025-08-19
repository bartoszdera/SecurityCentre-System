#ifndef IVALIDDATA_H
#define IVALIDDATA_H

#include <any>

class IValidData {
public:
    virtual ~IValidData() = default;

    // Check if the given credential matches
    virtual bool matches(const std::any& toMatch) const = 0;
};

#endif // IVALIDDATA_H
