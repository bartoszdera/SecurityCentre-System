#ifndef VALIDDATAWRAPPER_H
#define VALIDDATAWRAPPER_H

#include "IValidData.h"
#include "ValidData.h"

/*!
 * Template class that allows the use of ValidData with different data types while providing a common interface.
 */
template<typename T>
class ValidDataWrapper : public IValidData {
public:
    //! A constructor
    /*!
     * \param _data A vector of type T representing the valid data
     */
    ValidDataWrapper(const std::vector<T>& _data) : validData(_data) {}

    /*!
     * Method to check if the provided data matches any of the valid data.
     * \param toMatch A std::any object representing the data to be matched
     * \return A boolean indicating whether the data matches any of the valid data
     */
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
