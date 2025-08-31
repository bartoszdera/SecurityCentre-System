#ifndef IVALIDDATA_H
#define IVALIDDATA_H

#include <any>

/*!
 * IValidData interface for declaring a virtual method to check if given data matches.
 */
class IValidData {
public:
    /*!
     * virtual method to check if given data matches.
     * \param toMatch An object of type std::any representing the data to be matched
     */
    virtual bool matches(const std::any& toMatch) const = 0;
};

#endif // IVALIDDATA_H
