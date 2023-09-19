#include "Zombie.hpp"

int main()
{
    Zombie stackZombie("Stack Zombie");
    int N = 5;
    std::string zombieName = "mya";
    Zombie* horde = stackZombie.zombieHorde(N, zombieName);

    if (horde)
    {
        for (int i = 0; i < N; ++i) {
            horde[i].announce();
        }
        for (int i = 0; i < N; ++i) {
            horde[i].~Zombie(); // Explicitly call the destructor for each Zombie.
        }
        operator delete[](horde); // Release the allocated memory.
    }
    return 0;
}
