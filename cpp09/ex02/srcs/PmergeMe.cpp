#include "PmergeMe.hpp"

void	print(int n)
{
		std::cout << n << std::endl;
}

int		PmergeMe::checkOverflow(std::string const &str, size_t &size)
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

int		PmergeMe::parseInt(std::string const &str, int &n)
{
	size_t	i = 0;
	size_t	size = str.size();

	if (str[i] == '+' || str[i] == '-') {
		i++;
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

int	PmergeMe::countWord(char const *str)
{
	size_t	count = 0;

	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] != ' ') {
			count++;
		}
		while (str[i + 1] && str[i] != ' ') {
			i++;
		}
	}
	return (count);
}

void	PmergeMe::trimString(std::string &str)
{
	size_t	pos = str.find_first_not_of(" \t\r\b\n");

	if (pos != std::string::npos)
		str.erase(0, pos);
	pos = str.find_last_not_of(" \t\r\b\n");
	if (pos != std::string::npos && pos < str.size() - 1)
		str.erase(pos + 1);
}

int	*PmergeMe::parseArg(std::string str, size_t &tab_size)
{
	std::string	s;
	size_t		size = str.size();
	size_t		pos = 0;
	tab_size = PmergeMe::countWord(str.c_str());
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

int	PmergeMe::sortList(std::string str)
{
	size_t		size;
	int	*tab = PmergeMe::parseArg(str, size);
	if (tab == NULL) {
		return (1);
	}

	std::list<int>	list;

	for (size_t i = 0; i < size; i++) {
		list.push_back(tab[i]);
	}
	delete[] tab;
	return (0);
}


int	PmergeMe::sortVector(std::string str)
{
	size_t		size;
	int	*tab = PmergeMe::parseArg(str, size);
	if (tab == NULL) {
		return (1);
	}

	std::vector<int>	vector(size);

	for (size_t i = 0; i < size; i++) {
		vector[i] = tab[i];
	}
	delete[] tab;
	return (0);
}
