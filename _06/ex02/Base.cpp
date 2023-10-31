#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{  
    std::cout << "Destructor called" << std::endl;
}

Base *make_a()
{
    return new A();
}

Base *make_b()
{
    return new B();
}

Base *make_c()
{
    return new C();
}


Base * generate(void)
{
	Base *(*f[3])() = {make_a, make_c, make_b};
    srand(time(0));
    return f[rand() % 3]();
}

// void identify(Base* p)
// {
	
// }	

// void identify(Base& p)
// {

// }