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
		static size_t				size;
		static Container			*tmp;
		static unsigned int const	jacobsthal[27];

		PmergeMe();

		typedef typename Container::iterator	iterator;

		static void		sort(Container &, size_t &);
		static void		swapPair(iterator &, size_t &);
		static void		insert(iterator, iterator, size_t &);
		static iterator	binarySearch(int const &, iterator, iterator, size_t &);
};

#endif
