#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

#include <string>
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string const);
		DiamondTrap(DiamondTrap const &);
		~DiamondTrap();
		DiamondTrap	&operator=(DiamondTrap const &);
	
		void	attack(std::string const &);
		void	whoAmI();
		void	info();
	
	private:
		std::string	_Name;
};

#endif
