#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("Wrong animal")
{
	std::cout << "WrongAnimal: default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &cpy)
{
	*this = cpy;
	std::cout << "WrongAnimal: copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &cpy)
{
	this->_type = cpy.getType();
	return (*this);
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal makes a wrong sound"<< std::endl;
}
