#include <iostream>

#include "DiamondTrap.hpp"
// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

int main()
{
    DiamondTrap diamond("Clara_Diamond");
    diamond.whoAmI();
    diamond.attack("Scav");

    ClapTrap clap("Gabi_Clap");
    ScavTrap scav("Clara_Scav");
	scav.attack("Clara");
    FragTrap frag("Christian_Frag");
    frag.highFivesGuys();
    diamond.attack("Gabi_Clap");
    frag.attack("Gabi_Clap");

    scav.attack("Gabi_Clap");
    clap.takeDamage(6);
    clap.beRepaired(3);
}