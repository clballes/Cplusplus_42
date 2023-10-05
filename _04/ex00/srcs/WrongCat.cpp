#include "WrongCat.hpp"


WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
    std::cout << "Default constructor WrongCat called" << std::endl;

}

WrongCat::WrongCat(WrongCat const & src)
{
    std::cout << "Default copy assigment WrongCat called" << std::endl;
    *this = src;
	return ;

}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    std::cout << "Operator overload WrongCat called" << std::endl;
    WrongAnimal::_type = rhs.getType();
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Default destructor WrongCat called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "😼😼 MIAUUUUUUU 😼😼" << std::endl;

}
