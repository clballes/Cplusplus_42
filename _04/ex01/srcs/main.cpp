
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int len;
	len = 10;
	
	Animal **animal = new Animal*[len];

	for(int i = 0; i < (len / 2); i++)
	{
		animal[i] = new Dog();
	}

	for(int i = (len / 2); i < len; i++)
	{
		animal[i] = new Cat();
	}
	for(int i = 0; i < len; i++)
	{
		delete animal[i];
	}
	delete[] animal ;


// ------- AQUI COMENCA EL CODI DEL MAIN PER TEST -----------
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
    return 0;
}
