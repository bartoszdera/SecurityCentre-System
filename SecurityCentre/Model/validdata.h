#ifndef VALIDDATA_H
#define VALIDDATA_H

#include <vector>

template <typename T>
class ValidData
{
public:
    ValidData(std::vector<T> _data);
    void setData(std::vector<T> _data);
    void addData(T _dataUnit);
    std::vector<T> getData();
    bool matches(T toMatch);
private:
    std::vector<T> data;
};

template<typename T>
ValidData<T>::ValidData(std::vector<T> _data) : data(_data) {}

template<typename T>
void ValidData<T>::setData(std::vector<T> _data)
{
    data = _data;
}

template<typename T>
void ValidData<T>::addData(T _dataUnit)
{
    data.push_back(_dataUnit);
}

template<typename T>
std::vector<T> ValidData<T>::getData()
{
    return data;
}

template<typename T>
bool ValidData<T>::matches(T toMatch)
{
    for(auto dataUnit : data){
        if(dataUnit == toMatch){
            return true;
        }
    }
    return false;
}

#endif // VALIDDATA_H
