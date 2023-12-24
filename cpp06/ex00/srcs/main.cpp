#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{	
	if (argc == 1)
	{
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
