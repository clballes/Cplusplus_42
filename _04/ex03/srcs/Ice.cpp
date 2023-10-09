#include "Ice.hpp"


Ice::Ice(void)
{
	std::cout << " constructor default Ice " << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type)
{
    std::cout << " CONSTRUCTOR Ice el type en Ice es : " << type << std::endl;
    return ;
}

Ice* Ice::clone() const
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
    std::cout << "Destructor Ice" << std::endl;
    return;
}
