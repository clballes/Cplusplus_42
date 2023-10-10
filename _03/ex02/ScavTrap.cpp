
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"


ScavTrap::ScavTrap (void)
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "Constructor ScavTrap called for " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{  
    std::cout << " ScavTrap Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    std::cout << " ScavTrap Operator overload called" << std::endl;
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPoints = rhs.getHitPoints();
    this->_name = rhs.getName();
    this->_energyPoints = rhs.getEnergyPoints();
	return *this;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

//functions

void    ScavTrap::attack( std::string const& target )
{
    if ( this->_energyPoints <= 0 )
    {
        std::cout << "ScavTrap: " << this->_name << " is out of energy." << std::endl;
        return;
    }
    std::cout << "ScavTrap: " << this->_name << " attacks " << target << " at range, causing " << this->_attackDamage << " points of damage !" << std::endl;
    this->_energyPoints--;
}

void ScavTrap::guardGate( void )
{
    std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode." << std::endl;
}