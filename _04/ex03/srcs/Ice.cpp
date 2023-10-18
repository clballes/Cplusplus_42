#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default constructor ICE" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria("ice")
{
    *this = src;
}

Ice& Ice::operator=( Ice const & rhs)
{
    if (this != &rhs)
    {
         this->_type = rhs._type;
    }
    return *this;
}

AMateria* Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}

Ice::~Ice()
{
    std::cout << "Destructor ICE" << std::endl;
    return;
}
