#include "Weapon.hpp"
#include "HumanB.hpp"

void HumanB::setWeapon(const Weapon& humanWeapon)
{
        if (_weapon == nullptr) {
            _weapon = new Weapon(humanWeapon.getType());
        } else {
            _weapon->setType(humanWeapon.getType());
        }
    }

HumanB::~HumanB()
{
    delete _weapon; // Release dynamically allocated weapon when HumanB is destroyed
}

void HumanB::attack()
{
    if (_weapon != nullptr)
    {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    } 
    else 
    {
        std::cout << _name << " is unarmed and cannot attack." << std::endl;
    }
}