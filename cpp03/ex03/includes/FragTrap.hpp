#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

#include <string>
#include <iostream>
#include "ClapTrap.hpp"


class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const);
		FragTrap(FragTrap const &);
		~FragTrap();
		FragTrap	&operator=(FragTrap const &);
	
		void	attack(std::string const &);
		void	highFivesGuys();
};

#endif
