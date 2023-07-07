#include "Cat.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat: default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(Cat const &cpy): Animal(cpy)
{
	std::cout << "Cat: copy constructor called" << std::endl;
	*this = cpy;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &cpy)
{
	this->_type = cpy._type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat is meowing"<< std::endl;	
}
