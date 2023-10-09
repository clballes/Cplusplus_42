#include "Cure.hpp"

Cure::Cure(void)
{
	std::cout << " constructor default cure " << std::endl;
}

Cure::Cure(std::string const & type) : AMateria(type)
{
    std::cout << " CONSTRUCTOR CURE el type en cure es : " << type << std::endl;
    return ;
}

Cure* Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}

Cure::~Cure()
{
    std::cout << "Destructor Cure" << std::endl;
    return;
}
