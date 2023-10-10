#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap(const std::string& name);
        ScavTrap(ScavTrap const & src);
        ScavTrap & operator=(ScavTrap const & rhs);
        ~ScavTrap();

        void attack( std::string const& target );
        void guardGate( void );
};

#endif