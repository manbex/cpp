#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie <" << this->_name << "> created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie <" << this->_name << "> destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
