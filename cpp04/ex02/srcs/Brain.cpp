#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(Brain const &cpy)
{
	*this = cpy;
	std::cout << "Brain: cpy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain: destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &cpy)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = cpy.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea(int const i) const
{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	else
		return ("");
}

void		Brain::setIdea(int const i, std::string const &idea)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = idea;
}
