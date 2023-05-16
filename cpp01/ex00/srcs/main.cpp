#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}

void	randomChump(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}

int	main()
{
	Zombie	*zombie = newZombie("New");

	(*zombie).announce();
	randomChump("Random");
	delete zombie;
	return (0);
}
