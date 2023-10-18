

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << "Default constructor Cat called" << std::endl;
}

Cat::Cat(Cat const & src)
{
    std::cout << "Default copy assigment Cat called" << std::endl;
    *this = src;
	return ;
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Operator overload Cat called" << std::endl;
    Animal::_type = rhs.getType();
 	if (this->_brain)
 		delete this->_brain;
    this->_brain = new Brain();
    *this->_brain = rhs.getBrain();
	return *this;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Default destructor Cat called" << std::endl;
}

Brain & Cat::getBrain() const
{
    return *this->_brain;
}

void Cat::makeSound() const
{
    std::cout << "😼😼 MIAUUUUUUU 😼😼" << std::endl;
}
