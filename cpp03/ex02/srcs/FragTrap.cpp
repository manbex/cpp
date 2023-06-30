#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	this->_HitPoints = 100;
	this->_Energy = 100;
	this->_Damage = 30;
	std::cout << "FragTrap: default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string const name): ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_Energy = 100;
	this->_Damage = 30;
	std::cout << "FragTrap " << name << ": constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy): ClapTrap(cpy)
{
	std::cout << "FragTrap " << this->_Name << ": copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_Name << ": destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &cpy)
{
	this->_Name = cpy.getName();
	this->_HitPoints = cpy.getHitPoints();
	this->_Energy = cpy.getEnergy();
	this->_Damage = cpy.getDamage();
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (!this->_HitPoints)
		std::cout << "FragTrap " << this->_Name << " is KO" << std::endl; 
	else if (!this->_Energy)
		std::cout << "FragTrap " << this->_Name << " doesn't have enough energy" << std::endl; 
	else
	{
		std::cout << "FragTrap " << this->_Name << " attacks " << target << ", causing " \
		<< this->_Damage << " points of damage" << std::endl; 
		this->_Energy--;
	}
}

void	FragTrap::highFivesGuys()
{
	if (!this->_HitPoints)
		std::cout << "FragTrap " << this->_Name << " is KO" << std::endl; 
	else if (!this->_Energy)
		std::cout << "FragTrap " << this->_Name << " doesn't have enough energy" << std::endl; 
	else
	{
		std::cout << "FragTrap " << this->_Name << " begs for a high five" << std::endl;
		this->_Energy--;
	}
}
