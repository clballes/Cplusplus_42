#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default constructor CURE" << std::endl;
}

// Cure::Cure(std::string const & type) : AMateria(type)
// {
//     std::cout << "Constructor CURE - type:" << type << std::endl;
//     return ;
// }

Cure::Cure( Cure const & src) : AMateria("cure")
{
    *this = src;
    return ;
}

Cure&   Cure::operator=( const Cure& rhs )
{
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}


AMateria* Cure::clone() const
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
    std::cout << "Destructor CURE" << std::endl;
    return;
}
