#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: the program takes exactly 1 argument" << std::endl;
		return (1);
	}

	if (PmergeMe::sortList(argv[1]))
		return (1);
	if (PmergeMe::sortVector(argv[1]))
		return (1);
	return (0);
}
