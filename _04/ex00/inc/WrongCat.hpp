#ifndef __WRONG_CAT_H__
# define __WRONG_CAT_H__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( void );
        WrongCat(WrongCat const & src);
        WrongCat & operator=(WrongCat const & rhs);
        ~WrongCat();
        virtual void makeSound() const;
};

#endif