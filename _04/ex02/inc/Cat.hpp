#ifndef __CAT_H__
# define __CAT_H__

#include "AAnimal.hpp"

class Cat : public AAnimal {
    public:
        Cat( void );
        Cat(Cat const & src);
        Cat & operator=(Cat const & rhs);
        ~Cat();
        Brain & getBrain() const;
        virtual void makeSound() const;

    private:
        Brain* _brain;
};

#endif