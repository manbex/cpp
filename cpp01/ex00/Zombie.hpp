#ifndef	ZOMBIE_H__
# define ZOMBIE_H__

# include <string>

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();

		void	announce();

	private:
		std::string	_name;
};

#endif
