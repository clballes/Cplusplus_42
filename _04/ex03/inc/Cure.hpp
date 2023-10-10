
#ifndef __CURE_H__
# define __CURE_H__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
	    Cure( void );
        Cure( Cure const & );
        Cure& operator=( Cure const & );
        ~Cure();

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif