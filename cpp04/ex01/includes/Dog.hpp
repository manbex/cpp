#ifndef __DOG_H__
# define __DOG_H__

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class	Dog: public Animal
{
	public:
		Dog();
		Dog(std::string const &);
		Dog(Dog const &);
		virtual ~Dog();
		Dog	&operator=(Dog const &);

		virtual void	makeSound() const;
		Brain			*getBrain() const;

	private:
		Brain	*_brain;
};

#endif
