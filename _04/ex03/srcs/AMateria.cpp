
#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std:: cout << "Defautl constructor materia class" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << target.getName() << " the target is use" << std::endl;
    return ;
}

AMateria::~AMateria()
{
    std::cout << "Destructor AMateria" << std::endl;
    return;
}

