#include "Character.hpp"
#include "ICharacter.hpp"


Character::Character(std::string const &name) : _name(name)
{
	std::cout << "Constructor for CHARACTER called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = nullptr;
	}
}

Character::Character(Character const & src) :  _name(src._name)
{
	std::cout << "Copy operator called" << std::endl;
	*this = src;
	return;
}

Character & Character::operator=(Character const & rhs)
{
	std::cout << "Copy operation overload called" << std::endl;
	 if (this != &rhs)
    {
        this->_name = rhs._name;
        for (int i = 0; i < 4; i++)
            this->_inventory[i] = rhs._inventory[i];
    }
    return *this;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == nullptr)
		{
			this->_inventory[i] = m;
			std::cout << "Character " << this->_name << " equipped with " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << "Character " << this->_name << " can't equip " << m->getType() << std::endl;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr)
	{
		std::cout << "unequip el idx: " << idx << std::endl;
		_inventory[idx] = nullptr;
	}
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx] != nullptr)
	{
		// std::cout << "estoy function use in character" << idx << std::endl;
		_inventory[idx]->use(target);
	}
	else
		std::cout << "Character " << this->_name << " can't use" << std::endl;
}


Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			std::cout << "Destructor for Character CALLED" << std::endl;
			delete _inventory[i];
		}
	}
}