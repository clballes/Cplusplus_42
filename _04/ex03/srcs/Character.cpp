#include "Character.hpp"
#include "ICharacter.hpp"


Character::Character(std::string name) : _name(name)
{
	std::cout << "Constructor for CHARACTER CALLED" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = nullptr;
	}
}

Character::Character(Character const & src)
{
	std::cout << "Copy operator called" << std::endl;
	*this = src;
	return;
}

Character & Character::operator=(Character const & rhs)
{
	std::cout << "Copy operation overload called" << std::endl;
	rhs.getName();
	//fer deep copies 
	return *this;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = m;
	}
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::unequip(int idx)
{
	std::cout << "unequip el idx" << idx << std::endl;
	return ;
}

// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr)
	{
		std::cout << "estoy function use in character" << idx << std::endl;
		_inventory[idx]->use(target);
	}
}


Character::~Character()
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	delete _inventory[i];
	// }
	std::cout << "Destructor for Character CALLED" << std::endl;
}