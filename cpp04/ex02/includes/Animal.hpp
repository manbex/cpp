#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include "Brain.hpp"
#include <string>
#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(std::string const &);
		Animal(Animal const &);
		virtual ~Animal();
		Animal	&operator=(Animal const &);

		std::string	getType() const;
		virtual void	makeSound() const = 0;

	protected:
		std::string	_type;
};

#endif
