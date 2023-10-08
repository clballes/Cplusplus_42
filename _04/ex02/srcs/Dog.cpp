


#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog(void) : AAnimal("Dog")
{
    this->_brain = new Brain();
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
    AAnimal::_type = rhs.getType();
	this->_brain = new Brain();
	return *this;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Default destructor Dog called" << std::endl;
}

Brain Dog::getBrain()
{
    return *this->_brain;
}

void Dog::makeSound() const
{
    std::cout << "🐶🐶 GUAUU GUAU GUAUU 🐶🐶" << std::endl;

}