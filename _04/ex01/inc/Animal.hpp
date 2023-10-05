#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <iostream>
#include "Brain.hpp"

class Animal {
    public:
        Animal( void );
        Animal(std::string name);
        Animal(Animal const & src);
        Animal & operator=(Animal const & rhs);
        virtual ~Animal();
        virtual void makeSound() const;
        std::string getType() const;

    protected:
        std::string _type;
};

#endif