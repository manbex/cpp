#ifndef __WRONGANIMAL_H__
# define __WRONGANIMAL_H__

#include <string>
#include <iostream>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string const &);
		WrongAnimal(WrongAnimal const &);
		~WrongAnimal();
		WrongAnimal	&operator=(WrongAnimal const &);

		std::string	getType() const;
		void	makeSound() const;		

	protected:
		std::string	_type;
};

#endif
