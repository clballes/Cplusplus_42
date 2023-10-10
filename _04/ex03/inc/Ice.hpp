
#ifndef __ICE_H__
# define __ICE_H__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
		Ice(void);
        Ice( Ice const & );
        Ice& operator=( Ice const & );
        ~Ice();

        virtual AMateria* clone() const; // nose si calen q siguin virtuals
        virtual void use(ICharacter& target); // nose si calen q siguin virtuals
};

#endif