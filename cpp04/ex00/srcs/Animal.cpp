#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(Animal const &cpy)
{
	*this = cpy;
	std::cout << "Animal: copy constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor called" << std::endl;
}

Animal	&Animal::operator=(Animal const &cpy)
{
	this->_type = cpy.getType();
	return (*this);
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a random sound"<< std::endl;	
}
