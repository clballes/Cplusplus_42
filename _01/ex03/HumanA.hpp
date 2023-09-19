#include "Weapon.hpp"

#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

class HumanA {
    private:
        std::string _name;
        const Weapon& _weapon;

    public:
        HumanA(const std::string& humanName, const Weapon& weapon) : _name(humanName), _weapon(weapon) {}
        void attack();
};
#endif