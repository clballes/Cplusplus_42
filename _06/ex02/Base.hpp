#ifndef __BASE_H__
# define __BASE_H__

#include <iostream>


class Base
{
    public:
        virtual ~Base();

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
Base *make_a();
Base *make_b();
Base *make_c();

#endif