#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void    HumanA::attack()
{
    std::cout << "name: " << _name << " attacks with their: " << _weapon.getType() << std::endl;
}
