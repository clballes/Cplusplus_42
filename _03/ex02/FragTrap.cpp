#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
    std::cout << "Default constructor called in Frag trap" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap Constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
    std::cout << " FragTrap Copy Constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    std::cout << " FragTrap Operator overload called" << std::endl;
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPoints = rhs.getHitPoints();
    this->_name = rhs.getName();
    this->_energyPoints = rhs.getEnergyPoints();
	return *this;
}

FragTrap::~FragTrap()
{
    std::cout << " Deconstructor called in Frag trap" << std::endl;    
}

//functions

void FragTrap::highFivesGuys(void)
{
    std::cout << "High five with me!!  ✋ ✋ ✋" << std::endl;
}
