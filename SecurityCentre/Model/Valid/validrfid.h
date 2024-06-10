#include <string>
#include <vector>

#ifndef VALIDRFID_H
#define VALIDRFID_H

class ValidRFID
{
public:
    ValidRFID();
    inline std::vector<std::string> validRfids() { return this->validRfids_; }
private:
    std::vector<std::string> validRfids_;
};

#endif // VALIDRFID_H
