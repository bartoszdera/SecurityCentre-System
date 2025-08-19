#include "rfidagent.h"

template<typename T>
RFIDAgent<T>::RFIDAgent(int _id, const ValidData<T> &_validRFIDs) : AgentDevice<T>(_id), validRFIDs(_validRFIDs) {}

template<typename T>
AccessResult RFIDAgent<T>::verifyAccess(T credentials)
{
    return validRFIDs.matches(credentials) ? AccessResult::GRANTED : AccessResult::DENIED ;
}
