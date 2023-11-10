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
typename T::iterator easyfind( T& param, int num)
{
    typename T::iterator it = std::find(param.begin(), param.end(), num);
    if (it == param.end()) {
        throw NothingFound();
    }

    std::cout << "We found the occurence! " << *it << std::endl;
    return it;
}
#endif