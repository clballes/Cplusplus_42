#ifndef __FRAG_TRAP_H__
# define __FRAG_TRAP_H__

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap( void );
        FragTrap(std::string name);
        FragTrap(FragTrap const & src);
        FragTrap & operator=(FragTrap const & rhs);
        ~FragTrap();

        void highFivesGuys(void);
};

#endif