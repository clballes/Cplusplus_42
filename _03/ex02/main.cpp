
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Alex_Clap");
    ScavTrap scav("Gabriel_Scav");
    FragTrap frag("Clara_Frag");
    frag.highFivesGuys();
    // bob.attack("Christian");
    // hola.attack();
    // bob.takeDamage(6);
    // bob.beRepaired(3);


    clap.attack("Gabriel");
    scav.attack("Alex");
    scav.guardGate();
    frag.takeDamage(6);
    scav.beRepaired(10);
    clap.takeDamage(20);
    frag.takeDamage(200);
}