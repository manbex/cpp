#ifndef __CAT_H__
# define __CAT_H__

#include "Animal.hpp"
#include <string>
#include <iostream>

class	Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const &);
		Cat(Cat const &);
		~Cat();
		Cat	&operator=(Cat const &);

		virtual void	makeSound() const;		
};

#endif
