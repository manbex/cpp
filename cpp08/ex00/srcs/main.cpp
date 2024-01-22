#include "easyfind.hpp"

int	main()
{
	int					int_array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::vector<int>	a(int_array, int_array + 10);
	std::list<int>		b(int_array, int_array + 10);
	std::deque<int>		c(int_array, int_array + 10);

	test< std::vector<int> >(a, 5);
	test< std::vector<int> >(a, 42);
	std::cout << std::endl;

	test< std::list<int> >(b, 4);
	test< std::list<int> >(b, 42);
	std::cout << std::endl;

	test< std::deque<int> >(c, 3);
	test< std::deque<int> >(c, 42);
	std::cout << std::endl;

	return (0);
}
