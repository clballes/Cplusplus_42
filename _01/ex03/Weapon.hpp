#include <iostream>

#ifndef __WEAPON_H__
#define __WEAPON_H__

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(const std::string& initialType) : _type(initialType) {}
        const std::string& getType() const;
        void setType(const std::string& newType);
};
#endif