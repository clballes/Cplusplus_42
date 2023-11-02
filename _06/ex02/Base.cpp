#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{  
    std::cout << "Destructor called Base" << std::endl;
}

Base *make_a()
{
    std::cout << "generates: A" << std::endl;
    return new A();
}

Base *make_b()
{
    std::cout << "generates: B" << std::endl;
    return new B();
}

Base *make_c()
{
    std::cout << "generates: C" << std::endl;
    return new C();
}


Base * generate(void)
{
	Base *(*f[3])() = {make_a, make_c, make_b};
    srand(time(0));
    return f[rand() % 3]();
}

void identify(Base* p)
{
    std::cout << "Identify with Base *: ";

	if (dynamic_cast<A*>(p) != nullptr)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != nullptr)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != nullptr)
        std::cout << "C" << std::endl;
    else
        std::cout << "Invalid type" << std::endl;
}	

void identify(Base& p)
{
    std::cout << "Identify with Base &: ";
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << "Invalid type" << std::endl;
			}
		}
	}
}