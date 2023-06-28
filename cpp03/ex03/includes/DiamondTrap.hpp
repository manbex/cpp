#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

class	DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string const);
		DiamondTrap(DiamondTrap const &);
		~DiamondTrap();
		DiamondTrap	&operator=(DiamondTrap const &);

		std::string	getName() const;

		void	attack(const std::string &);
		void	whoAmI();
		void	info();
	
	private:
		std::string	_Name;
};

#endif
