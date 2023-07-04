#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &cpy): Animal(cpy)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = cpy;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat: destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &cpy)
{
	this->_type = cpy.getType();
	if (this->_brain != NULL)
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, cpy.getIdea(i));
	else
		this->_brain = cpy.getBrain();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat is meowing"<< std::endl;	
}

Brain			*Cat::getBrain() const
{
	Brain *tmp = new Brain();
	*tmp = *this->_brain;
	return (tmp);	
}

void	Cat::setIdea(int const &i, std::string const &idea)
{
	this->_brain->setIdea(i, idea);
}

void	Cat::getIdeas() const
{
	std::string	tmp;

	for (int i = 0; i < 100; i++)
	{
		tmp = this->_brain->getIdea(i);
		if (tmp.compare(""))
			std::cout << "idea " << i << ": " << tmp << std::endl;
	}
}
		
std::string	Cat::getIdea(int const &i) const
{
	return (this->_brain->getIdea(i));
}
