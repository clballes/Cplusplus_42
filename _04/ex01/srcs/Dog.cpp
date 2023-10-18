#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog(void) : Animal("Dog")
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
    Animal::_type = rhs.getType();
 	if (this->_brain)
 		delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = rhs.getBrain();
	return *this;
}

Brain & Dog::getBrain() const
{
    return *this->_brain;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Default destructor Dog called" << std::endl;
}


void Dog::makeSound() const
{
    std::cout << "🐶🐶 GUAUU GUAU GUAUU 🐶🐶" << std::endl;

}