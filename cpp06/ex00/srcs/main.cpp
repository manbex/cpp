#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{	
	if (argc == 1)
	{
		std::string	arg[] = {
			"a",
			"42",
			"4566465464646656546464646",
			"42.5f",
			"42.5",
			"nan",
			"+inf",
			"-inf",
			"+inff",
			"-inff",
			"1000000000000000000000000000000000000000.0",
			"1000000000000000000000000000000000000000.0f",
			""
		};
		for (int i = 1; !arg[i].empty(); i++)
		{
			std::cout << "input: \"" << arg[i] << "\":" << std::endl;
			ScalarConverter::convert(arg[i]);
			std::cout << std::endl;
		}
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::cout << "input: \"" << argv[i] << "\":" << std::endl;
		ScalarConverter::convert(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}
