#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cctype>
#include <algorithm>

template<typename Container>
class	PmergeMe
{
	public:
		static void	mergeInsertionSort(Container &);

	private:
		PmergeMe();

		typedef typename Container::iterator	iterator;

		static void	sort(Container &, size_t, size_t const &);
		static void	swapElement(iterator &, size_t &);
};

#endif
