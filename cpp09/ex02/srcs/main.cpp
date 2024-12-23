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
	std::vector<int>	*input = NULL;
	struct timeval		start1, start2, stop1, stop2;

	try
	{
		// test deque
		gettimeofday(&start1, NULL);
		deque = initDeque(argc, argv);
		if (deque == NULL) {
			return (1);
		}
		PmergeMe<std::deque<int> >::mergeInsertionSort(*deque);
		gettimeofday(&stop1, NULL);

		//test vector
		gettimeofday(&start2, NULL);
		vector = initVector(argc, argv);
		if (vector == NULL) {
			return (1);
		}
		PmergeMe<std::vector<int> >::mergeInsertionSort(*vector);
		gettimeofday(&stop2, NULL);

		input = initVector(argc, argv);
		if (input == NULL) {
			return (1);
		}
		std::cout << "Before:	";
		print(input->begin(), input->end());
		std::cout << "After:	";
		print(vector->begin(), vector->end());
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: ";
		std::cout << (stop1.tv_sec - start1.tv_sec) * 1000000 + stop1.tv_usec - start1.tv_usec;
		std::cout << " us" << std::endl;
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: ";
		std::cout << (stop2.tv_sec - start2.tv_sec) * 1000000 + stop2.tv_usec - start2.tv_usec;
		std::cout << " us" << std::endl;

		delete deque;
		delete vector;
		delete input;
	}
	catch (std::exception &e)
	{
		delete vector;
		delete deque;
		delete input;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
