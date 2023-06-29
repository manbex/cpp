#ifndef __BRAIN_H__
# define __BRAIN_H__

#include <string>

class	Brain
{
	public:
		Brain();
		Brain(Brain const &);
		~Brain();
		Brain	&operator=(Brain const &);

		std::string	getIdea(int const i) const;

	private:
		std::string	_ideas[100];
}

#endif
