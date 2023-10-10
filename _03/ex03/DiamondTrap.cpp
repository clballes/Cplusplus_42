#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void )
{
    std::cout << "Default constructor called in Diamond trap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap Constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src)
{
    std::cout << " DiamondTrap Copy Constructor called" << std::endl;
    *this = src;
    return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
    std::cout << " DiamondTrap Operator overload called" << std::endl;
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPoints = rhs.getHitPoints();
    this->_name = rhs.getName();
    this->_energyPoints = rhs.getEnergyPoints();
	return *this;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << " Deconstructor called in Diamond trap" << std::endl;    
}

//functions

void DiamondTrap::whoAmI( void )
{
    std::cout << "DiamondTrap name is: " << _name << std::endl;
    std::cout << "Clap trap is: " << this->ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}