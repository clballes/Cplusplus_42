#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include "Brain.hpp"

class AAnimal
{
    public:
        AAnimal();
        AAnimal(std::string name);
        virtual void makeSound() const = 0;
        AAnimal(const AAnimal &src);

        AAnimal &operator=(const AAnimal &rhs);
        
        virtual ~AAnimal();
        std::string getType() const;
    protected:
        std::string _type;
};

#endif