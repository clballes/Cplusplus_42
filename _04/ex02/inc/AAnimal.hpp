#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include "Brain.hpp"

class AAnimal
{
    public:
        AAnimal();
        AAnimal(std::string name);
        AAnimal(const AAnimal &src);
        AAnimal &operator=(const AAnimal &rhs);
        virtual ~AAnimal();
        
        virtual void makeSound() const = 0;
        std::string getType() const;

    protected:
        std::string _type;
};

#endif