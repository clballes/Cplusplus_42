
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

	// Brain brain;

	// //Set ideas
	// for (int i = 0; i < 10; i++)
	// {
	// 	brain.setIdeas(i, "hola guapi");
	// }

	// Brain brain2;
	// brain2 = brain;
	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "BRAIN: " << brain.getIdeas(i) << std::endl;
	// }

	// for (int i = 0; i < 10; i++)
	// {
	// 	std::cout << "BRAIN 2: " << brain2.getIdeas(i) << std::endl;
	// }

// ------- AQUI COMENCA EL CODI DEL MAIN PER TEST DE CANONICAL FORM -----------

	// Dog *	dog1 = new Dog();
	// dog1->getBrain().setIdeas( 0 , "Dog2 was created with this value");

	// Dog	*	dog2 = new Dog(*dog1);
	// Dog	*	dog3 = new Dog();


	// dog3->getBrain().setIdeas( 0 , "Estamos intetnando resolverlo dog3");
	// std::cout << "dog3 ideas: " << dog3->getBrain().getIdeas(0) << std::endl;
	// dog3 = dog2;
	// std::cout << "dog3 ideas DEBERIA SER LA FRASE DE DOG2: " << dog3->getBrain().getIdeas(0) << std::endl;
	// dog3->getBrain().setIdeas( 0 , "CAMBIAMOS DE IDEA !!!!");
	// std::cout << "dog3 ideas CAMBIO: " << dog3->getBrain().getIdeas(0) << std::endl;
	// std::cout << "HOLA: " << dog2->getBrain().getIdeas(0) << std::endl;

	// std::cout << "Deep copy: ";
	// dog1->getBrain().setIdeas( 0 , "Dog1 is the only that is changed");
	// if (!(dog2->getBrain().getIdeas(0)).compare("Dog2 was created with this value"))
	// 	std::cout << "TRUE" << std::endl;
	// else
	// 	std::cout << "FALSE" << std::endl;
	// std::cout << std::endl;
}
