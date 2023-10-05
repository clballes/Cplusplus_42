
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int len;
	len = 10;
	
	Animal *animal = new Animal[len];

	for(int i = 0; i < (len / 2); i++)
	{
		std::cout << "la i es" << i  << std::endl;
		animal[i] = Dog();
	}

	for(int i = (len / 2); i < len; i++)
	{
		std::cout << "la i es en cat " << i  << std::endl;

		animal[i] = Cat();
	}
	std::cout << animal << std::endl;


    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
    return 0;
}
