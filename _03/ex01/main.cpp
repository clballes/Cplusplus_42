
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Gabi");
    ScavTrap scav("gabitrap");

    clap.attack("Christian");
    scav.guardGate();
    // hola.attack();
    scav.takeDamage(6);
    clap.beRepaired(3);
}