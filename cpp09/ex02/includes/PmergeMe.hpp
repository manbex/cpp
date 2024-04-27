#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <cctype>
#include <algorithm>

class	PmergeMe
{
	public:
		static int	sortList(std::string);
		static int	sortVector(std::string);

	private:
		PmergeMe();

		static int	parseInt(std::string const &str, int &);
		static int	countWord(char const *);
		static void	trimString(std::string &);
		static int	checkOverflow(std::string const &, size_t &);
		static int	*parseArg(std::string, size_t &);
};

#endif
