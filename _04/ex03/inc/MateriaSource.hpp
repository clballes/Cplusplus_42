
#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

#include <ostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	private:
		AMateria *_copyMateria[4];

	public:
		MateriaSource( void );
		virtual ~MateriaSource();
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif