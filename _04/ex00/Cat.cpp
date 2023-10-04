


#include "Cat.hpp"


Cat::Cat(void) : Animal("Cat") {
    std::cout << "Default constructor Cat called" << std::endl;

}
// {
//     name = "cat";
//     this->_type = name;
//     // if (this->_type.empty())
//     //     name = "cat";
// }

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
	return *this;
}

Cat::~Cat()
{
    std::cout << "Default destructor Cat called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "😼😼 MIAUUUUUUU 😼😼" << std::endl;

}
