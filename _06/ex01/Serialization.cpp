#include "Serialization.hpp"

Serialization::Serialization(void)
{
    std::cout << "Constructor called" << std::endl;
}

Serialization::Serialization(Serialization const & src)
{
    std::cout << "Destructor called" << std::endl;
    (void)src;
}

Serialization & Serialization::operator=(Serialization const & rhs)
{
    std::cout << "Destructor called" << std::endl;
    (void)rhs;
    return *this;
}

Serialization::~Serialization()
{  
    std::cout << "Destructor called" << std::endl;
}
