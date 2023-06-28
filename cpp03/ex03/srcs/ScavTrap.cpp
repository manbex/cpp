#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	this->_HitPoints = 100;
	this->_Energy = 50;
	this->_Damage = 20;
	std::cout << "ScavTrap: default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const name): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_Energy = 50;
	this->_Damage = 20;
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
	if (!this->_Energy)
		std::cout << "ScavTrap " << this->_Name << " doesn't have enough energy" << std::endl; 
	else if (!this->_HitPoints)
		std::cout << "ScavTrap " << this->_Name << " is KO" << std::endl; 
	else
	{
		std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " \
		<< this->_Damage << " points of damage" << std::endl; 
		this->_Energy--;
	}
}

void	ScavTrap::guardGate()
{
	if (!this->_Energy)
		std::cout << "ScavTrap " << this->_Name << " doesn't have enough energy" << std::endl; 
	else if (!this->_HitPoints)
		std::cout << "ScavTrap " << this->_Name << " is KO" << std::endl; 
	else
	{
		std::cout << "ScavTrap " << this->_Name << " entered Gate keeper mode" << std::endl; 
		this->_Energy--;
	}
}
