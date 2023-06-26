#ifndef	ZOMBIE_H__
# define ZOMBIE_H__

# include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		Zombie();
		~Zombie();

		void	announce();
		void	setName(std::string name);

	private:
		std::string	_name;
};

#endif
