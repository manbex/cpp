#include "PmergeMe.hpp"

template <typename Container>
size_t	PmergeMe<Container>::size = 0;

template <typename Container>
Container	*PmergeMe<Container>::tmp = NULL;

template <typename Container>
void	PmergeMe<Container>::swapPair(iterator &itPair, size_t &elemSize)
{
	int	tmp;

	for (iterator it = itPair; it != itPair + elemSize; it++)
	{
		tmp = *it;
		*it = *(it + elemSize);
		*(it + elemSize) = tmp;
	}
}

template <typename Container>
void	PmergeMe<Container>::insert(iterator &itElem, iterator &itPos, size_t &elemSize)
{
	if (itElem == itPos) {
		return ;
	}
	int	tmp[elemSize];

	size_t	i = 0;
	for (iterator it = itElem; it < itElem + elemSize; it++) {
		tmp[i++] = *it;
	}
	i = 0;
	for (iterator it = itElem + elemSize - 1; it > itPos + elemSize; it--) {
		*it = *(it - elemSize);
	}
	for (iterator it = itPos; it < itPos + elemSize; it++) {
		*it = tmp[i++];
	}
}

template <typename Container>
void	PmergeMe<Container>::sort(Container &container, size_t &elemSize)
{
	size_t	nbElem = PmergeMe::size / elemSize;
	size_t	pairSize = elemSize * 2;
	size_t	nbPair = PmergeMe::size / pairSize;
	std::cout << "Elem: " << nbElem << std::endl;
	std::cout << "Pair: " << nbPair << std::endl;
	std::cout << "elemSize: " << elemSize << std::endl;

	if (nbElem == 1) {
		return ;
	}
	
	iterator	begin = container.begin();
	iterator	end = container.end();

	for (iterator it = begin; it < end && it + pairSize < end; it += pairSize)
	{
		if (*(it + elemSize - 1) > *(it + pairSize - 1)) {
			swapPair(it, elemSize);
		}
		std::cout << "pair: ";
		for (iterator itt = it; itt < it + elemSize; itt++) {
			std::cout << *itt << " ";
		}
		std::cout << "+ ";
		for (iterator itt = it + elemSize; itt < it + pairSize; itt++) {
			std::cout << *itt << " ";
		}
		std::cout << std::endl;
	}

	if (nbElem % 2 != 0)
	{
		iterator	it = begin + (pairSize * nbPair);
		std::cout << "stray: ";
		for (iterator itt = it; itt < it + elemSize; itt++) {
			std::cout << *itt << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	sort(container, pairSize);

	std::cout << std::endl;
}

template <typename Container>
void	PmergeMe<Container>::mergeInsertionSort(Container &container)
{
	PmergeMe::size = container.size();
	if (PmergeMe::size < 2)
	{
		PmergeMe::size = 0;
		return ;
	}

	PmergeMe::tmp = new Container(PmergeMe::size);
	size_t	elemSize = 1;
	sort(container, elemSize);
	PmergeMe::size = 0;
	delete PmergeMe::tmp;
	PmergeMe::tmp = NULL;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
