#include "AAnimal.hpp"

AAnimal::AAnimal( void )
{
    std::cout << "Default constructor Aanimal called" << std::endl;
}

AAnimal::AAnimal(std::string name) : _type(name) {}

AAnimal::AAnimal(AAnimal const & src)
{
    std::cout << "Default copy assigment Aanimal called" << std::endl;
    *this = src;
	return ;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
    std::cout << "Operator overload Aanimal called" << std::endl;
    _type = rhs.getType();
	return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Default destructor Aanimal called" << std::endl;
}

void    AAnimal::makeSound() const
{
    std::cout << "I AM JUST AN AANIMAL MAKiNG SOUNDS" << std::endl;
}

std::string AAnimal::getType() const
{
   return  this->_type;
}