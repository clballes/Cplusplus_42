
#ifndef __Ice_H__
# define __Ice_H__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice(std::string const & type);
        virtual Ice* clone() const; // nose si calen q siguin virtuals
        virtual void use(ICharacter& target); // nose si calen q siguin virtuals
        ~Ice();
};

#endif