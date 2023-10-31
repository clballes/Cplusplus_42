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

uintptr_t Serialization::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialization::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}