#ifndef __CAT_H__
# define __CAT_H__

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat( void );
        Cat(Cat const & src);
        Cat & operator=(Cat const & rhs);
        ~Cat();
        virtual void makeSound() const;
};

#endif