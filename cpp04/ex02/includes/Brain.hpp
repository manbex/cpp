#ifndef __BRAIN_H__
# define __BRAIN_H__

#include <string>
#include <iostream>

class	Brain
{
	public:
		Brain();
		Brain(Brain const &);
		~Brain();
		Brain	&operator=(Brain const &);

		std::string	getIdea(int const) const;
		void		setIdea(int const, std::string const &);

	private:
		std::string	_ideas[100];
};

#endif
