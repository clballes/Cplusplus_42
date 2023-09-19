#include <iostream>

#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

class Zombie {
    private:
        std::string _name;
    public:
        Zombie(std::string name) : _name(name) {} // Constructor to set the zombie's name
        std::string getName(void);
        void announce( void );
        Zombie* newZombie( std::string name );
        void randomChump( std::string name );
        ~Zombie();
};
#endif