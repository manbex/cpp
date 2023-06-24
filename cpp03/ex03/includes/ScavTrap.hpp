#ifndef __SCAVTRAP_H__
# define __SCCAVTRAP_H__

#include <string>
#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const);
		ScavTrap(ScavTrap const &);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap const &);
	
		void	attack(std::string const &);
		void	guardGate();
};

#endif
