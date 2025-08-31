#include <string>
#include <vector>

#ifndef VALIDFINGERPRINT_H
#define VALIDFINGERPRINT_H

/*!
 * ValidFingerprint class for storing valid fingerprint identifiers.
 */
class ValidFingerprint
{
public:
    //! A default constructor
    ValidFingerprint();

    /*!
     * Method to get a valid fingerprint identifiers.
     * \return A std::vector of valid fingerprint identifiers
     */
    inline std::vector<std::string> validFingerprints() { return this->validFingerprints_; }

private:
    std::vector<std::string> validFingerprints_;
};

#endif // VALIDFINGERPRINT_H
