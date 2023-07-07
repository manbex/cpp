#include "Dog.hpp"

Dog::Dog(): Animal()
{
	std::cout << "Dog: default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::Dog(Dog const &cpy): Animal(cpy)
{
	std::cout << "Dog: copy constructor called" << std::endl;
	*this = cpy;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->_type = cpy._type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Dog is barking"<< std::endl;	
}
