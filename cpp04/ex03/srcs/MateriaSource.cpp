#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource: default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &cpy)
{
	std::cout << "MateriaSource: constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	*this = cpy;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource: destructor called" << std::endl;

	AMateria	*tmp[4] = {NULL, NULL, NULL, NULL};

	for (int i = 0; i < 4; i++)
	{
		int	a = 1;
		for (int j = 0; j < 4; j++)
			if (this->_materia[i] == tmp[j])
				a = 0;
		if (a)
			tmp[i] = this->_materia[i];
	}
	for (int i = 0; i < 4; i++)
		if (tmp[i])
			delete tmp[i];
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &cpy)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		if (cpy._materia[i])
			this->_materia[i] = cpy._materia[i]->clone();
		else
			this->_materia[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Source can't learn materia: invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_materia[i])
		{
			std::cout << "Source learns materia " << m->getType() << std::endl;
			this->_materia[i] = m;
			return ;
		}
	}
	std::cout << "Source can't learn more materias" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (!type.compare(this->_materia[i]->getType()))
		{
			std::cout << "Source creates materia " << this->_materia[i]->getType() << std::endl;
			return (this->_materia[i]->clone());
		}
	}
	std::cout << "Source can't create materia: materia unknown" << std::endl;
	return (NULL);
}
