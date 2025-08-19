#ifndef VALIDDATAWRAPPER_H
#define VALIDDATAWRAPPER_H

#include "IValidData.h"
#include "validdata.h"

template<typename T>
class ValidDataWrapper : public IValidData {
public:
    ValidDataWrapper(const std::vector<T>& _data) : validData(_data) {}

    bool matches(const std::any& toMatch) const override {
        if (toMatch.type() != typeid(T)) return false;
        try {
            const T& value = std::any_cast<const T&>(toMatch);
            return validData.matches(value);
        } catch (const std::bad_any_cast&) {
            return false;
        }
    }

private:
    ValidData<T> validData;
};

#endif // VALIDDATAWRAPPER_H
