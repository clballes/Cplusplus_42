
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("")
{
	std:: cout << "Default constructor Amateria class" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const
{
    return this->_type;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}


AMateria::~AMateria()
{
    std::cout << "Destructor AMateria" << std::endl;
    return;
}

