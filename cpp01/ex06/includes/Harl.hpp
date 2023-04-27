#ifndef __HARL_H__
# define __HARL_H__

#include <string>
#include <iostream>

class	Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string level);

	private:
		void	debug();
		void	info();
		void	warning();
		void	error();
};

#endif
