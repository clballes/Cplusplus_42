#include "Weapon.hpp"

#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

class HumanB {
    private:
        std::string _name;
    public:
        HumanB(const std::string& humanName) : _name(humanName) {}
        void attack();
};
#endif