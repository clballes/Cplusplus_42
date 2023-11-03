#ifndef __SERIALIZATION_H__
# define __SERIALIZATION_H__

#include <iostream>
#include "Data.hpp"

class Serialization 
{
	private:
        Serialization(void);
        Serialization(Serialization const & src);
        Serialization & operator=(Serialization const & rhs);
        ~Serialization();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif