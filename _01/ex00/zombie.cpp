
#include <iostream>
#include "zombie.hpp"

void    Zombie::announce()
{
    std::cout << _name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
    return new Zombie(name);
}

void    Zombie::randomChump(std::string name)
{
    std::cout << "zombie random chump mode" << std::endl;
    Zombie zombie(name);
    std::cout << "zombie created with name: " << name << std::endl;
    zombie.announce();
}

Zombie::~Zombie()
{
    std::cout << "Zombie name: " << _name << "   has been destroyed" << std::endl;
}

std::string Zombie::getName() {
        return _name;
}