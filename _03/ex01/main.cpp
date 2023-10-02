#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ClapTrap bob("Gabi");
    ScavTrap hola("gabitrap");

    bob.attack("Christian");
    // hola.attack();
    bob.takeDamage(6);
    bob.beRepaired(3);
}