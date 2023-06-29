#include "Dog.hpp"

Dog::Dog(): Animal()
{
	this->_type = "Dog";
	std::cout << "Dog: default constructor called" << std::endl;
}

Dog::Dog(Dog const &cpy): Animal(cpy)
{
	*this = cpy;
	std::cout << "Dog: copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->_type = cpy.getType();
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog is woofing"<< std::endl;	
}
