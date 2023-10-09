#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	std::cout << " constructor default Materia Source " << std::endl;

}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *a)
{
	for (int i = 0; i < 4; i++)
	{
		_copyMateria[i] = a;
	}

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i) {
			if (_copyMateria[i] != nullptr && _copyMateria[i]->getType() == type) {
				return _copyMateria[i]->clone();
			}
		}
		return 0;
}