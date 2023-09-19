#include <iostream>

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(std::string _name) : _name(_name) {}
        void announce(void);
        Zombie* zombieHorde( int N, std::string name );
        ~Zombie();
};
#endif