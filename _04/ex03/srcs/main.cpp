
#include "Cure.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

int main()
{
	// Character myCharacter;

	Character myCharacter("clara");
    Cure* cureclass = new Cure("cure");

    // Call the equip function on your Character object
    myCharacter.equip(cureclass);
	delete cureclass;
	// AMateria *m;
	// m = new AMateria;

    // Cure a("cure");

    // ICharacter& targetCharacter = myCharacter;


	// // myCharacter.equip(a);

	// myCharacter.use(2, targetCharacter);

    // Ice b("ice");

    // a.use(targetCharacter);
    // b.use(targetCharacter);

    // Ice b("b");
	// a.use();

    // std::cout << a.getType() << std::endl;
    // std::cout << a.getType() << std::endl;

    // std::cout << b.getType() << std::endl;
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;
    // return 0;
}