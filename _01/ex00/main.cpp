#include "zombie.hpp"

int main()
{
    Zombie stackZombie("Stack Zombie");
    stackZombie.announce();

    // Create a random Zombie on the stack using randomChump function
    Zombie* heapZombie = nullptr; 
    heapZombie = stackZombie.newZombie("HeapZombie");
    heapZombie->announce();


    // Create a random Zombie on the stack using randomChump function
    stackZombie.randomChump("RandomZombie");
    // Clean up the heap-allocated Zombie
    delete heapZombie;
    return 0;
}