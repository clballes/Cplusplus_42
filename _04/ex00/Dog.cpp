


#include "Dog.hpp"


Dog::Dog(void) : Animal("Dog") {
    std::cout << "Default constructor Dog called" << std::endl;

}


Dog::Dog(Dog const & src)
{
    std::cout << "Default copy assigment Dog called" << std::endl;
    *this = src;
	return ;

}

Dog & Dog::operator=(Dog const & rhs)
{
    std::cout << "Operator overload Dog called" << std::endl;
    Animal::_type = rhs.getType();
	return *this;
}

Dog::~Dog()
{
    std::cout << "Default destructor Dog called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "🐶🐶 GUAUU GUAU GUAUU 🐶🐶" << std::endl;

}