#ifndef __DIAMOND_TRAP_H__
# define __DIAMOND_TRAP_H__

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"


class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap( void );
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const & src);
        DiamondTrap & operator=(DiamondTrap const & rhs);
        void whoAmI();
        ~DiamondTrap();

    private:
        std::string _name;
};

#endif