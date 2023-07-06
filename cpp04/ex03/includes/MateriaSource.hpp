#ifndef __MATERIASOURCE_H__
# define __MATERIASOURCE_H__

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &);
		virtual	~MateriaSource();
		MateriaSource	&operator=(MateriaSource const &);

		virtual void		learnMateria(AMateria *);
		virtual AMateria	*createMateria(std::string const &type);
	
	private:
		AMateria	*_materia[4];
};

#endif
