
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("")
{
	std:: cout << "Default constructor Amateria class" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std:: cout << "Default constructor Amateria class type: " << this->_type << std::endl;
	return ;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

AMateria::AMateria( AMateria const & src )
{
    *this = src;
	return ;
}

AMateria &	AMateria::operator=( AMateria const & rhs)
{
	( void ) rhs;
	return (*this);
}


AMateria::~AMateria()
{
    std::cout << "Destructor AMateria" << std::endl;
    return;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}

