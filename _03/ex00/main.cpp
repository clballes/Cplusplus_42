#include <iostream>

#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Gabi");

    bob.attack("Christian");
    bob.takeDamage(6);
    bob.beRepaired(3);
}