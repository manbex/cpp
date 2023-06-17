#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

#include <string>
#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const);
		ScavTrap(ScavTrap const &);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap const &);
	
		void	attack(std::string const &);
		void	highFivesGuys();
};

#endif
