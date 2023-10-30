#ifndef __SERIALIZATION_H__
# define __SERIALIZATION_H__

#include <iostream>
class Serialization 
{
    public:
        Serialization(void);
        Serialization(Serialization const & src);
        Serialization & operator=(Serialization const & rhs);
        ~Serialization();
    
    //methods
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif