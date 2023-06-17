#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

#include <iostream>
#include <string>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string const);
		ClapTrap(ClapTrap const &);
		~ClapTrap();
		ClapTrap	&operator=(ClapTrap const &);

		std::string	getName() const;
		int			getHitPoints() const;
		int			getEnergy() const;
		int			getDamage() const;

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	info();

	private:
		std::string			_Name;
		unsigned int		_HitPoints;
		unsigned int		_Energy;
		unsigned int		_Damage;
};

#endif
