#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_Name = "Default";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_Energy = ScavTrap::_Energy;
	this->_Damage = FragTrap::_Damage;
	std::cout << "DiamondTrap: default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	ClapTrap::_Name += "_clap_name";
	this->_Name = name;
	this->_HitPoints = FragTrap::_HitPoints;
	this->_Energy = ScavTrap::_Energy;
	this->_Damage = FragTrap::_Damage;
	std::cout << "DiamondTrap " << name << ": constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy): ClapTrap(cpy), FragTrap(cpy), ScavTrap(cpy)
{
	*this = cpy;
	std::cout << "DiamondTrap " << this->_Name << ": copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_Name << ": destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &cpy)
{
	this->_Name = cpy.getName();
	this->_HitPoints = cpy.getHitPoints();
	this->_Energy = cpy.getEnergy();
	this->_Damage = cpy.getDamage();
	return (*this);
}

std::string	DiamondTrap::getName() const
{
	return (this->_Name);	
}

void	DiamondTrap::whoAmI()
{
	if (!this->_HitPoints)
		std::cout << "DiamondTrap " << this->_Name << " is KO" << std::endl; 
	else if (!this->_Energy)
		std::cout << "DiamondTrap " << this->_Name << " doesn't have enough energy" << std::endl; 
	else
		std::cout << "Am I " << this->_Name << ", or am I " << ClapTrap::_Name << "?" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::info()
{
	std::cout << "Name = " << this->_Name << ", HP = " << this->_HitPoints \
	<< ", Energy = " << this->_Energy<< ", Damage = " << this->_Damage << std::endl;
}
