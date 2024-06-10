#include <string>
#include <vector>

#ifndef VALIDFINGERPRINT_H
#define VALIDFINGERPRINT_H

class ValidFingerprint
{
public:
    ValidFingerprint();
    inline std::vector<std::string> validFingerprints() { return this->validFingerprints_; }

private:
    std::vector<std::string> validFingerprints_;
};

#endif // VALIDFINGERPRINT_H
