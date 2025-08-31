#include <string>
#include <vector>

#ifndef VALIDFACIAL_H
#define VALIDFACIAL_H

/*!
 * ValidFacial class for storing valid facial identifiers.
 */
class ValidFacial
{
public:
    //! A default constructor
    ValidFacial();

    /*!
     * Method to get a valid facial identifiers.
     * \return A std::vector of valid facial identifiers
     */
    inline std::vector<std::string> validFacials() { return this->validFacials_; }

private:
    std::vector<std::string> validFacials_;
};

#endif // VALIDFACIAL_H
