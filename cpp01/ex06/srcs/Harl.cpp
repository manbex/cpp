#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\nI love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do !\n" << std::endl;
}

void	Harl::info()
{
	std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger ! \
If you did, I wouldn’t be asking for more !\n" << std::endl;
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. \
I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\nThis is unacceptable ! \
I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		i = 0;

	for (int &n = i; n < 4; n++)
		if (levels[n] == level)
			break ;
	switch (i)
	{
		case 0:
			(this->*f[0])();
			// fall through
		case 1:
			(this->*f[1])();
			// fall through
		case 2:
			(this->*f[2])();
			// fall through
		case 3:
			(this->*f[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
