


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
    std::cout << "Default constructor Wronganimal called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : _type(name) {}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "Default copy assigment Wronganimal called" << std::endl;
    *this = src;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
    std::cout << "Operator overload Wronganimal called" << std::endl;
    _type = rhs.getType();
	return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Default destructor Wronganimal called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "I AM JUST AN WrongANIMAL MAKiNG SOUNDS" << std::endl;
}

std::string WrongAnimal::getType() const
{
   return  this->_type;
}