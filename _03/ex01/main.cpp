#include <iostream>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap bob("Gabi");
    ScavTrap hola("gabitrap");

    bob.attack("Christian");
    hola.guardGate();
    // hola.attack();
    bob.takeDamage(6);
    bob.beRepaired(3);
}