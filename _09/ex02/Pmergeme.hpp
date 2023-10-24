#ifndef ____PMERGEME__H___
#define ____PMERGEME__H___

#include <iostream>
class Pmergeme
{
    public:
        Pmergeme(std::string argv);
        Pmergeme(Pmergeme const & src);
        Pmergeme & operator=(Pmergeme const & rhs);
        ~Pmergeme();
};
#endif