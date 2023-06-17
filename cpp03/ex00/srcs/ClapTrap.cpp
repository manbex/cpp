#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _Name("Default"), _HitPoints(10), _Energy(10), _Damage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const name): _Name(name), _HitPoints(10), _Energy(10), _Damage(0)
{
	std::cout << "Constructor for \"" << name <<"\" called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
	*this = cpy;
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &cpy)
{
	this->_Name = cpy.getName();
	this->_HitPoints = cpy.getHitPoints();
	this->_Energy = cpy.getEnergy();
	this->_Damage = cpy.getDamage();
	return (*this);
}

std::string	ClapTrap::getName() const
{
	return (this->_Name);
}

int	ClapTrap::getHitPoints() const
{
	return (this->_HitPoints);
}

int	ClapTrap::getEnergy() const
{
	return (this->_Energy);
}

int	ClapTrap::getDamage() const
{
	return (this->_Damage);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_Energy)
	{
		std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " \
		<< this->_Damage << " points of damage" << std::endl; 
		this->_Energy--;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " doesn't have energy points" << std::endl; 
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_HitPoints)
		this->_HitPoints = 0;
	else
		this->_HitPoints -= amount;
	std::cout << "ClapTrap " << this->_Name << " takes " << amount << " damage, leaving him at " \
	<< this->_HitPoints << " hit points" << std::endl; 
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Energy)
	{
		this->_HitPoints += amount;
		std::cout << "ClapTrap " << this->_Name << " gains " << amount << \
		" hit points, leaving him at " << this->_HitPoints << " hit points" << std::endl;
		this->_Energy--;
	}
	else
		std::cout << "ClapTrap " << this->_Name << " doesn't have energy points" << std::endl; 
}

void	ClapTrap::info()
{
	std::cout << "Name = " << this->_Name << ", HP = " << this->_HitPoints \
	<< ", Energy = " << this->_Energy<< ", Damage = " << this->_Damage << std::endl;
}
