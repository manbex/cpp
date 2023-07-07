#ifndef __ANIMAL_H__
# define __ANIMAL_H__

#include <string>
#include <iostream>

class	Animal
{
	public:
		Animal();
		Animal(Animal const &);
		virtual ~Animal();
		Animal	&operator=(Animal const &);

		std::string		getType() const;
		virtual void	makeSound() const;		

	protected:
		std::string	_type;
};

#endif
