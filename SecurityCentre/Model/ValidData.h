#ifndef VALIDDATA_H
#define VALIDDATA_H

#include <vector>

/*!
 * ValidData class implementing methods to manage a collection of valid data entries.
 */
template <typename T>
class ValidData
{
public:
    //! A constructor
    /*!
     * \param _data A vector of type T representing the initial valid data entries
     */
    ValidData(std::vector<T> _data) : data(_data) {};

    /*!
     * Method to set the valid data entries.
     * \param _data A vector of type T representing the new valid data entries
     */
    void setData(std::vector<T> _data)
    {
        data = _data;
    }

    /*!
     * Method to add a single valid data entry.
     * \param _dataUnit A data entry of type T to be added to the valid data entries
     */
    void addData(T _dataUnit)
    {
        data.push_back(_dataUnit);
    }

    /*!
     * Method to get the valid data entries.
     * \return A vector of type T representing the valid data entries
     */
    std::vector<T> getData()
    {
        return data;
    }

    /*!
     * Method to check if a given data entry matches any of the valid data entries.
     * \param toMatch A data entry of type T to be checked against the valid data entries
     * \return A boolean value indicating whether the given data entry matches any of the valid data entries
     */
    bool matches(T toMatch) const
    {
        for(auto dataUnit : data){
            if(dataUnit == toMatch){
                return true;
            }
        }
        return false;
    }

private:
    std::vector<T> data;
};

#endif // VALIDDATA_H
