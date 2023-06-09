#include "Character.hpp"

Character::Character()
{
	std::cout << "Character: default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &cpy)
{
	std::cout << "Character " << cpy.getName() << ": copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = cpy;
}

Character::Character(std::string const &name): _name(name)
{
	std::cout << "Character " << name << ": constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::~Character()
{
	std::cout << "Character " << this->_name << ": destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character	&Character::operator=(Character const &cpy)
{
	this->_name = cpy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (cpy._inventory[i])
			this->_inventory[i] = cpy._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << this->_name << ": can't equip materia: invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (m->isEquipped())
		{
			std::cout << this->_name << ": can't equip materia " << m->getType() \
			<< ": materia already equipped"<< std::endl;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			std::cout << this->_name << " equips materia " << m->getType() << std::endl;
			this->_inventory[i] = m;
			m->equip();
			return ;
		}
	}
	std::cout << this->_name << ": can't equip materia " << m->getType() \
	<< ": inventory full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << this->_name << " unequips materia in slot " << idx << std::endl;
		this->_inventory[idx]->unequip();
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << this->_name << ": can't unequip materia: no materia in slot " \
		<< idx << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << this->_name << ": can't use materia: no materia in slot " \
		<< idx << std::endl;
}
