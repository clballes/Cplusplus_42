#ifndef __SCAV_TRAP_H__
# define __SCAV_TRAP_H__

#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap( void );
        ScavTrap(const std::string& name);
        ScavTrap(ScavTrap const & src);
        ScavTrap & operator=(ScavTrap const & rhs);
        void guardGate( void );
        ~ScavTrap();
};

#endif