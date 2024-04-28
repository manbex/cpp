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

int	countWord(char const *str)
{
	size_t		count = 0;
	std::string	set = " \t\r\b\n";

	for (size_t i = 0; str[i]; i++)
	{
		if (set.find(str[i]) == std::string::npos) {
			count++;
		}
		while (str[i + 1] && set.find(str[i]) == std::string::npos) {
			i++;
		}
	}
	return (count);
}

void	trimString(std::string &str)
{
	size_t	pos = str.find_first_not_of(" \t\r\b\n");

	if (pos != std::string::npos)
		str.erase(0, pos);
	pos = str.find_last_not_of(" \t\r\b\n");
	if (pos != std::string::npos && pos < str.size() - 1)
		str.erase(pos + 1);
}

int	*parseArg(std::string str, size_t &tab_size)
{
	std::string	s;
	size_t		size = str.size();
	size_t		pos = 0;
	tab_size = countWord(str.c_str());
	int			*n = new int[tab_size];

	trimString(str);
	for (int i = 0; pos != std::string::npos; i++)
	{
		pos = str.find_first_of(" \t\r\b\n"); 
		int	j = 1;
		while (pos + j < size && str[pos + j] == ' '){
			j++;
		}
		if (pos != std::string::npos)
		{
			s = str.substr(0, pos);
			str.erase(0, pos + j);
		}
		else {
			s = str;
		}
		if (parseInt(s, n[i]))
		{
			delete[] n;
			return (NULL);
		}
	}
	return (n);
}

void	print(int n)
{
		std::cout << n << std::endl;
}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: the program takes exactly 1 argument" << std::endl;
		return (1);
	}

	try
	{
		size_t	size;
		int		*tab = parseArg(argv[1], size);
		if (tab == NULL) {
			return (1);
		}
		std::deque<int>		deque;
		std::vector<int>	vector(size);
		for (size_t i = 0; i < size; i++) {
			deque.push_back(tab[i]);
			vector[i] = tab[i];
		}
		delete[] tab;
		PmergeMe<std::deque<int> >::mergeInsertionSort(deque);
	//	PmergeMe<std::vector<int> >::mergeInsertionSort(vector);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
