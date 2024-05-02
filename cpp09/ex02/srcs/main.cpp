#include "PmergeMe.hpp"

int		checkOverflow(std::string const &str, size_t &size)
{
	size_t	i = 0;

	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	if (size - i > 10)
		return (1);
	if (size - i < 10)
		return (0);

	std::string test = str[0] == '-' ? "2147483648" : "2147483647";
	size_t j = 0;
	while (j < 10)
	{
		if (str[i] < test[j]) {
			return (0);
		}
		if (str[i] > test[j]) {
			return (1);
		}
		i++;
		j++;
	}
	return (0);
}

int		parseInt(std::string const &str, int &n)
{
	size_t	i = 0;
	size_t	size = str.size();

	if (str[i] == '+' || str[i] == '-') {
		i++;
	}
	if (i == size) {
		std::cerr << "Error: wrong argument: " << str << std::endl;
		return (1);
	}
	while (i < size)
	{
		if (!isdigit(str[i]))
		{
			std::cerr << "Error: wrong argument: " << str << std::endl;
			return (1);
		}
		i++;
	}
	if (checkOverflow(str, size))
	{
		std::cerr << "Error: int overflow: " << str << std::endl;
		return (1);
	}
	std::stringstream	sstream;
	sstream << str;
	sstream >> n;
	return (0);
}

std::vector<int>	*initVector(int	 &size, char **(&argv))
{
	std::vector<int>	*vector = new std::vector<int>(size - 1);

	for (int i = 1; i < size; i++)
	{
		if (parseInt(std::string(argv[i]), (*vector)[i - 1]))
		{
			delete vector;
			return (NULL);
		}
	}
	return (vector);
}

std::deque<int>		*initDeque(int	&size, char **(&argv))
{
	std::deque<int>	*deque = new std::deque<int>;
	int				n;

	for (int i = 1; i < size; i++)
	{
		if (parseInt(std::string(argv[i]), n))
		{
			delete deque;
			return (NULL);
		}
		deque->push_back(n);
	}
	return (deque);
}

void	print(std::vector<int>::iterator it, std::vector<int>::iterator ite)
{
	for (;it < ite; it++)
	{
		std::cout << *it;
		if (it < ite - 1) {
			std::cout << " ";
		}
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: no arguments" << std::endl;
		return (1);
	}

	std::deque<int>		*deque = NULL;
	std::vector<int>	*vector = NULL;
	try
	{
		deque = initDeque(argc, argv);
		if (deque == NULL) {
			return (1);
		}
		PmergeMe<std::deque<int> >::mergeInsertionSort(*deque);
		delete deque;

		vector = initVector(argc, argv);
		if (vector == NULL) {
			return (1);
		}

		std::cout << "Before:	";
		print(vector->begin(), vector->end());

		PmergeMe<std::vector<int> >::mergeInsertionSort(*vector);

		std::cout << "After:	";
		print(vector->begin(), vector->end());

		delete vector;
	}
	catch (std::exception &e)
	{
		delete vector;
		delete deque;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
