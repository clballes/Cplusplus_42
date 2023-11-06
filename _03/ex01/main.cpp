
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    // ClapTrap clap("Alex");
    ScavTrap scav("Gabriel");

    // clap.attack("Gabriel");
    scav.attack("Alex");
    scav.guardGate();
    scav.takeDamage(6);
    scav.beRepaired(10);
    // clap.takeDamage(20);
    scav.takeDamage(200);

}