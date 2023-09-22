#include "Weapon.hpp"

#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

class HumanB {
    private:
        std::string _name;
        Weapon* _weapon; // Store a reference to Weapon
; // Store a reference to the Weapon object
    public:
        HumanB(const std::string& humanName) : _name(humanName), _weapon(nullptr) {}
        void setWeapon(const Weapon& humanWeapon);
        void attack();
        ~HumanB();
};
#endif

// HumanA and HumanB are almost the same except for these two tiny details:
// • HumanB may not always have a Weapon, whereas HumanA will always be armed.