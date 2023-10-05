
#include "ClapTrap.hpp"

//Constructor calleddd!!
ClapTrap::ClapTrap( void )
{
    std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{  
    std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    std::cout << "Operator overload called" << std::endl;
    this->_attackDamage = rhs.getAttackDamage();
    this->_hitPoints = rhs.getHitPoints();
    this->_name = rhs.getName();
    this->_energyPoints = rhs.getEnergyPoints();
	return *this;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "Destructor called" << std::endl;
}

// getter function
std::string ClapTrap::getName() const
{ 
    return this->_name; 
}

int ClapTrap::getHitPoints() const
{
    return this->_hitPoints; 
}

int ClapTrap::getEnergyPoints() const
{ 
    return this->_energyPoints; 
}

int ClapTrap::getAttackDamage() const
{ 
    return this->_attackDamage; 
}

//Public member functions
void ClapTrap::attack(const std::string& target)
{
    if ( this->_energyPoints <= 0)
    {
        std::cout << "cannot attack bc there is no more hit points: " << this->_hitPoints << std::endl;
        return ;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap: " << _name << " attacks: " <<  target << " points of damage: " << this->_attackDamage << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints >= amount)
    {
        this->_hitPoints -= amount;
        std::cout << "ClapTrap " << this->_name << " took damage, its hit points after the damage are " << this->_hitPoints << std::endl;
    }
    else
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " took damage, its hit points after the damage are " << this->_hitPoints << std::endl; 
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if ( this->_energyPoints <= 0)
    {
        std::cout << "cannot be repaired bc there is no more energy points: " << this->_energyPoints << std::endl;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " was repaired, its hit points after repair are " << this->_hitPoints << std::endl;
}