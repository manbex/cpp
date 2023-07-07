#ifndef __CAT_H__
# define __CAT_H__

#include "Brain.hpp"
#include "Animal.hpp"
#include <string>
#include <iostream>

class	Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const &);
		Cat(Cat const &);
		virtual ~Cat();
		Cat	&operator=(Cat const &);

		virtual void	makeSound() const;
		Brain			*getBrain() const;
		void			setIdea(int const &, std::string const &);
		void			showIdeas() const;
		std::string		getIdea(int const &) const;

	private:
		Brain	*_brain;
};

#endif
