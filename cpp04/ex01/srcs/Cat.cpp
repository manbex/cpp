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
	if (&cpy != this)
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
