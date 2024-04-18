#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: program must take exactly 1 argument" << std::endl;
		return (1);
	}
	try {
		RPN::calculate(std::string(argv[1]));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
