#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class	WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string const &);
		WrongCat(WrongCat const &);
		~WrongCat();
		WrongCat	&operator=(WrongCat const &);

		void	makeSound() const;		
};

#endif
