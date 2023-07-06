#include "Cure.hpp"

Cure::Cure(): AMateria("Cure")
{
	std::cout << "Cure: default constructor called" << std::endl;
}

Cure::Cure(Cure const &cpy): AMateria("Cure") 
{
	std::cout << "Cure: copy constructor called" << std::endl;
	(void)cpy;
}

Cure::~Cure()
{
	std::cout << "Cure: destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &cpy)
{
	(void)cpy;
	return (*this);
}

AMateria	*Cure::clone() const
{
	AMateria *tmp = new Cure();
	return (tmp);
}

void			Cure::use(ICharacter &target)
{
	std::cout << "Cure : \"* heals " << target.getName() << "'s wounds *\""<< std::endl;
}
