#ifndef __WRONG_ANIMAL_H__
# define __WRONG_ANIMAL_H__

#include <iostream>
#include "Animal.hpp"

class WrongAnimal {
    public:
        WrongAnimal( void );
        WrongAnimal( std::string name );
        WrongAnimal(WrongAnimal const & src);
        WrongAnimal & operator=(WrongAnimal const & rhs);
        ~WrongAnimal();

        std::string getType() const;
        virtual void makeSound() const;

     protected:
        std::string _type;

};

#endif