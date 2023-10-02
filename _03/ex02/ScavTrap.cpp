
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"


ScavTrap::ScavTrap (void)
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
    this->_name = (name);
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap Constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{  
    std::cout << " ScavTra Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    std::cout << " ScavTra Operator overload called" << std::endl;
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPoints = rhs.getHitPoints();
    this->_name = rhs.getName();
    this->_energyPoints = rhs.getEnergyPoints();
	return *this;
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "ScavTra Destructor called" << std::endl;
}

//fucitons

void ScavTrap::guardGate( void )
{
    
}