
#ifndef __AMATERIA_H__
# define __AMATERIA_H__

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;

    public:
		AMateria(void);
        AMateria(std::string const & type);
        AMateria( AMateria const & src );
        //falta operator pero nose si cal preguntar classe abstarct canonical form 
        virtual ~AMateria();
        
        std::string const & getType() const;
       	virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif