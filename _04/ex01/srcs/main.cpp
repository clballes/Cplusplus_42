
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	// int len;
	// len = 10;
	
	// Animal **animal = new Animal*[len];

	// for(int i = 0; i < (len / 2); i++)
	// {
	// 	animal[i] = new Dog();
	// }

	// for(int i = (len / 2); i < len; i++)
	// {
	// 	animal[i] = new Cat();
	// }
	// for(int i = 0; i < len; i++)
	// {
	// 	delete animal[i];
	// }
	// delete[] animal ;

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

// ------- AQUI COMENCA EL CODI DEL MAIN PER TEST -----------

	// Dog *	dog1 = new Dog();
	// dog1->getBrain().setIdeas(0, "emdic clara");
	// std::cout << "BRAIN: " << dog1->getBrain().getIdeas(0) << std::endl;

		Dog *	dog1 = new Dog();
	dog1->getBrain().setIdeas( 0 , "Dog2 was created with this value");

	Dog	*	dog2 = new Dog(*dog1);
	std::cout << std::endl;

	std::cout << "Deep copy: ";
	dog1->getBrain().setIdeas( 0 , "Dog1 is the only that is changed");
	if (!(dog2->getBrain().getIdeas(0)).compare("Dog2 was created with this value"))
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
	std::cout << std::endl;

	std::cout << "Protected string: " << std::endl;
		dog1->getBrain().setIdeas(200 , "Dog2 was created with this value");
		dog1->getBrain().getIdeas(200);

	delete dog1;
	delete dog2;
	// std::cout << "BRAIN 2: " << dog1 << std::endl;

	// dog1->setIdeas(0, "holaa");
// 	dog1->getBrain().setIdeas( 0 , "Dog2 was created with this value");

// 	Dog	*	dog2 = new Dog(*dog1);
// 	std::cout << std::endl;

// 	std::cout << "Deep copy: ";
// 	dog1->getBrain().setIdeas( 0 , "Dog1 is the only that is changed");
// 	if (!(dog2->getBrain().getIdeas(0)).compare("Dog2 was created with this value"))
// 		std::cout << "TRUE" << std::endl;
// 	else
// 		std::cout << "FALSE" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Protected string: " << std::endl;
// 		dog1->getBrain().setIdeas(200 , "Dog2 was created with this value");
// 		dog1->getBrain().getIdeas(200);

// 	delete dog1;
// 	delete dog2;
// 	return (0);	
// si igual brain a = brain b
// print brainn a 
// canvio brain a
// print brain b no deberia estar cambiado sino es una shallow copy
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j;//should not create a leak
    // delete i;
    // return 0;
}
