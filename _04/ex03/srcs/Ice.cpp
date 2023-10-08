#include "Ice.hpp"

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
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}

Ice::~Ice()
{
    std::cout << "Destructor Ice" << std::endl;
    return;
}
