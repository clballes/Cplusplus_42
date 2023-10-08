
#ifndef __CURE_H__
# define __CURE_H__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure(std::string const & type);
        virtual Cure* clone() const; // nose si calen q siguin virtuals
        virtual void use(ICharacter& target); // nose si calen q siguin virtuals
        ~Cure();
};

#endif