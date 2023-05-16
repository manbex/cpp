#ifndef	ZOMBIE_H__
# define ZOMBIE_H__

# include <string>

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
