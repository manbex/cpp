#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &cpy): Animal(cpy)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	this->_brain = NULL;
	*this = cpy;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog: destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->_type = cpy.getType();
	if (this->_brain != NULL)
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, cpy.getIdea(i));
	else
		this->_brain = cpy.getBrain();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog is woofing"<< std::endl;	
}

Brain			*Dog::getBrain() const
{
	Brain *tmp = new Brain();
	*tmp = *this->_brain;
	return (tmp);	
}

void	Dog::setIdea(int const &i, std::string const &idea)
{
	this->_brain->setIdea(i, idea);
}

void	Dog::getIdeas() const
{
	std::string	tmp;

	for (int i = 0; i < 100; i++)
	{
		tmp = this->_brain->getIdea(i);
		if (tmp.compare(""))
			std::cout << "idea " << i << ": " << tmp << std::endl;
	}
}
		
std::string	Dog::getIdea(int const &i) const
{
	return (this->_brain->getIdea(i));
}
