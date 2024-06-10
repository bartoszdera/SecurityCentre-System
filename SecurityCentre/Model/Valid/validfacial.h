#include <string>
#include <vector>

#ifndef VALIDFACIAL_H
#define VALIDFACIAL_H

class ValidFacial
{
public:
    ValidFacial();
    inline std::vector<std::string> validFacials() { return this->validFacials_; }

private:
    std::vector<std::string> validFacials_;
};

#endif // VALIDFACIAL_H
