#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
	this->_Name = "Default";
	ClapTrap::_Name += "_clap_name";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_Energy = ScavTrap::_Energy;
	this->_Damage = FragTrap::_Damage;
	std::cout << "DiamondTrap: default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const name): ClapTrap(name)
{
	this->_Name = name;
	ClapTrap::_Name += "_clap_name";
	this->_HitPoints = FragTrap::_HitPoints;
	this->_Energy = ScavTrap::_Energy;
	this->_Damage = FragTrap::_Damage;
	std::cout << "DiamondTrap " << name << ": constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &cpy): ClapTrap(), FragTrap(), ScavTrap()
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
	this->_Name = cpy._Name;;
	ClapTrap::_Name = cpy._Name + "_clap_name";
	this->_HitPoints = cpy._HitPoints;
	this->_Energy = cpy._Energy;
	this->_Damage = cpy._Damage;
	return (*this);
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
