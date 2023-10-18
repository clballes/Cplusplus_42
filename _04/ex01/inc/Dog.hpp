#ifndef __DOG_H__
# define __DOG_H__

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog( void );
        Dog(Dog const & src);
        Dog & operator=(Dog const & rhs);
        ~Dog();
        Brain& getBrain() const;
        virtual void makeSound() const;

    private:
        Brain* _brain;
};

#endif