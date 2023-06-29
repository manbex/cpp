#include "Brain.hpp"

Brain::Brain()
{
}

Brain::Brain(Brain const &cpy)
{
	*this = cpy;
}

Brain::~Brain()
{
}

Brain	&Brain::operator=(Brain const &cpy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = cpy.getIdea[i];
	return (*this);
}

std::string	getIdea(int const i) const
{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	else
		return ("");
}
