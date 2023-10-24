#include "Pmergeme.hpp"

Pmergeme::Pmergeme(std::string argv)
{
    std::cout << "Constructor called" << argv << std::endl;

}
Pmergeme::Pmergeme(Pmergeme const & src)
{  
    *this = src;

}
Pmergeme & Pmergeme::operator=(Pmergeme const & rhs)
{
    (void)rhs;
    return *this;
}
Pmergeme::~Pmergeme()
{
    std::cout << "Destructor called" << std::endl;
}