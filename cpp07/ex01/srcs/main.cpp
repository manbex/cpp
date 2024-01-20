#include "iter.hpp"

int	main()
{
	int			a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string	b[] = {"string 1", "string 2", "string 3", "string 4", "string 5"};
	
	iter<int>(a, 10, &print<int>);
	std::cout << std::endl;
	iter<std::string>(b, 5, &print<std::string>);
	return (0);
}
