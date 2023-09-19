#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

const std::string& Weapon::getType() const
{
    return _type;
}

void Weapon::setType(const std::string& newType)
{
    _type = newType;
}