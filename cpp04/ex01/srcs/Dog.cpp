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
	*this = cpy;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor called" << std::endl;
	delete this->_brain;
}

Dog	&Dog::operator=(Dog const &cpy)
{
	this->_type = cpy.getType();
	if (&cpy != this)
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
