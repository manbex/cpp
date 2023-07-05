#include "AMateria.hpp"

AMateria::AMateria(): _equipped(0)
{
}

AMateria::AMateria(AMateria const &cpy): _equipped(0)
{
	*this = cpy;
}

AMateria::AMateria(std::string const &type): _type(type), _equipped(0)
{
}

AMateria::~AMateria()
{
}

AMateria	&AMateria::operator=(AMateria const &cpy)
{
	(void)cpy;
	return (*this);
}


std::string const	&AMateria::getType() const
{
	return (this->_type);
}

int					AMateria::isEquipped() const
{
	return (this->_equipped);
}

void				AMateria::equip()
{
	this->_equipped = 1;	
}

void				AMateria::unequip()
{
	this->_equipped = 0;	
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
