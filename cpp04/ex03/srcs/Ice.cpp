#include "Ice.hpp"

Ice::Ice(): AMateria("Ice")
{
	std::cout << "Ice: default constructor called" << std::endl;
}

Ice::Ice(Ice const &cpy): AMateria("Ice") 
{
	std::cout << "Ice: copy constructor called" << std::endl;
	(void)cpy;
}

Ice::~Ice()
{
	std::cout << "Ice: destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &cpy)
{
	(void)cpy;
	return (*this);
}

AMateria	*Ice::clone() const
{
	AMateria *tmp = new Ice();
	return (tmp);
}

void			Ice::use(ICharacter &target)
{
	std::cout << "Ice : \"* shoots an ice bolt at " << target.getName() << " *\""<< std::endl;
}
