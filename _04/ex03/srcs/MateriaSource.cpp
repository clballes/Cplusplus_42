#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "constructor default Materia Source " << std::endl;
	for (int i = 0; i < 4; i++)
        _copyMateria[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    *this = src;
	return ;
}

MateriaSource& MateriaSource::operator=( MateriaSource const & rhs )
{
    if (this != &rhs)
    {
        for (int i = 0; i < 4; i++)
            _copyMateria[i] = rhs._copyMateria[i];
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
        delete _copyMateria[i];
}


void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_copyMateria[i] == NULL )
		{
			_copyMateria[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::getMateria( std::string const & type )
{
    for (int i = 0; i < 4; i++)
        if (_copyMateria[i] && _copyMateria[i]->getType() == type)
            return _copyMateria[i];
    return NULL;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (_copyMateria[i] != nullptr && _copyMateria[i]->getType() == type)
		{
			return _copyMateria[i]->clone();
		}
	}
	return 0;
}