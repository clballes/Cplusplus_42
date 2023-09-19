#include "Zombie.hpp"

void    Zombie::announce()
{
    std::cout << "----- zombie announcing -----" << std::endl;

    std::cout << _name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}



Zombie* Zombie::zombieHorde(int N, std::string name) {
    if (N <= 0) {
        return nullptr; // Return nullptr for invalid input.
    }
   // Allocate memory for an array of Zombie objects
    void* rawMemory = operator new[](sizeof(Zombie) * N);

    Zombie* horde = static_cast<Zombie*>(rawMemory);

    for (int i = 0; i < N; ++i) {
        new (&horde[i]) Zombie(name); // Placement new to construct each Zombie.
    }

    return horde;
}

 Zombie::~Zombie()
 {
    std::cout << "destructor called: " << _name << std::endl;
 }