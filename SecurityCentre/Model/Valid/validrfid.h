#include <string>
#include <vector>

#ifndef VALIDRFID_H
#define VALIDRFID_H

/*!
 * ValidRFID class for storing valid RFID identifiers.
 */
class ValidRFID
{
public:
    //! A default constructor
    ValidRFID();

    /*!
     * Method to get a valid RFID identifiers.
     * \return A std::vector of valid RFID identifiers
     */
    inline std::vector<std::string> validRfids() { return this->validRfids_; }
private:
    std::vector<std::string> validRfids_;
};

#endif // VALIDRFID_H
