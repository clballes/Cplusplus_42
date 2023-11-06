#ifndef __EASYFIND__H__
#define __EASYFIND__H__

#include <iostream>
#include <algorithm>
#include <vector>

#include <stdexcept>

class NothingFound : public std::exception
{
public:
    virtual const char* what() const throw()
    {
        return "Nothing found";
    }
};

template< typename T>
void easyfind(const T& param, int num)
{
    typename T::const_iterator it;
    for (it = param.begin(); it != param.end(); ++it)
    {
        if (*it == num)
        {
            std::cout << "Occurrence found: " << num << std::endl;
            return;
        }
    }
    throw NothingFound();
}
#endif