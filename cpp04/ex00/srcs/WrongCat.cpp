#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->_type = "Wrong Cat";
	std::cout << "WrongCat: default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &cpy): WrongAnimal(cpy)
{
	*this = cpy;
	std::cout << "WrongCat: copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &cpy)
{
	this->_type = cpy.getType();
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat is meowing"<< std::endl;	
}
