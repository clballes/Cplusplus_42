#ifndef __CHARACTER_H__
# define __CHARACTER_H__

#include <iostream>

#include "AMateria.hpp"
#include "ICharacter.hpp"


class Character : public ICharacter
{
	private:
		AMateria* _inventory[4];
		std::string _name;

    public:
        Character(std::string name);
		Character(Character const & src);
        Character & operator=(Character const & rhs);
        
		void equip(AMateria* m);
        void unequip(int idx);
        std::string const & getName() const;
        void use(int idx, ICharacter& target);
		
		virtual ~Character();
};

#endif
