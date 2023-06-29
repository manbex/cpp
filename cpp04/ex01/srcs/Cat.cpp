#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->_type = "Cat";
	std::cout << "Cat: default constructor called" << std::endl;
}

Cat::Cat(Cat const &cpy): Animal(cpy)
{
	*this = cpy;
	std::cout << "Cat: copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor called" << std::endl;
}

Cat	&Cat::operator=(Cat const &cpy)
{
	this->_type = cpy.getType();
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Cat is meowing"<< std::endl;	
}
