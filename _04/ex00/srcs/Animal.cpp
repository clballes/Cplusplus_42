


#include "Animal.hpp"

Animal::Animal( void )
{
    std::cout << "Default constructor animal called" << std::endl;
}

Animal::Animal(std::string name) : _type(name) {}

Animal::Animal(Animal const & src)
{
    std::cout << "Default copy assigment animal called" << std::endl;
    *this = src;
	return ;
}

Animal & Animal::operator=(Animal const & rhs)
{
    std::cout << "Operator overload animal called" << std::endl;
    _type = rhs.getType();
	return *this;
}

Animal::~Animal()
{
    std::cout << "Default destructor animal called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "I AM JUST AN ANIMAL MAKiNG SOUNDS" << std::endl;
}

std::string Animal::getType() const
{
   return  this->_type;
}