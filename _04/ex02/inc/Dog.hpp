#ifndef __DOG_H__
# define __DOG_H__

#include <iostream>
#include "AAnimal.hpp"

class Dog : public AAnimal {
    public:
        Dog( void );
        Dog(Dog const & src);
        Dog & operator=(Dog const & rhs);
        ~Dog();
        Brain getBrain();
        virtual void makeSound() const;

    private:
        Brain* _brain;
};

#endif