#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	std::cout << "ScavTrap " << name << ": constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy): ClapTrap(cpy)
{
	std::cout << "ScavTrap " << this->_Name << ": copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_Name << ": destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &cpy)
{
	this->_Name = cpy.getName();
	this->_HitPoints = cpy.getHitPoints();
	this->_Energy = cpy.getEnergy();
	this->_Damage = cpy.getDamage();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_Energy)
	{
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " \
		<< this->_Damage << " points of damage" << std::endl; 
		this->_Energy--;
	}
	else
		std::cout << "ScavTrap " << this->_Name << " doesn't have energy points" << std::endl; 
}

void	ScavTrap::guardGate()
{
	if (this->_Energy)
	{
		std::cout << "ScavTrap " << this->_Name << " entered Gate keeper mode" << std::endl; 
		this->_Energy--;
	}
	else
		std::cout << "ScavTrap " << this->_Name << " doesn't have energy points" << std::endl; 
}
