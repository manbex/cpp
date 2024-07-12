#include "PmergeMe.hpp"

template <typename Container>
size_t	PmergeMe<Container>::size = 0;

template <typename Container>
Container	*PmergeMe<Container>::tmp = NULL;

template <typename Container>
unsigned int const	PmergeMe<Container>::jacobsthal[27] = {
	3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 
	349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971};

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
void	PmergeMe<Container>::insert(iterator itElem, iterator itPos, size_t &elemSize)
{
	if (itElem == itPos) {
		return ;
	}

	iterator	ite = PmergeMe::tmp->end();
	for (iterator it = ite - 1; it >= itPos + elemSize; it--) {
		*it = *(it - elemSize);
	}
	for (iterator it = itPos; it < itPos + elemSize; it++) {
		*it = *(itElem++);
	}
}

template <typename Container>
typename PmergeMe<Container>::iterator	PmergeMe<Container>::binarySearch(int const &value, iterator low, iterator high, size_t &elemSize)
{
	iterator	mid = low + ((std::distance<iterator>(low, high) / elemSize) / 2 * elemSize);
	long int	comp = (value > *(mid + elemSize - 1)) ? 1 : (value < *(mid + elemSize - 1)) ? -1 : 0;

	if (mid == low && comp <= 0) {
		return (low);
	}
	if (mid == high && comp >= 0) {
		return (high + elemSize);
	}
	if (comp > 0) {
		return (binarySearch(value, mid + elemSize, high, elemSize));
	}
	if (comp < 0) {
		return (binarySearch(value, low, mid - elemSize, elemSize));
	}
	return (mid);
}

template <typename Container>
void	PmergeMe<Container>::sort(Container &container, size_t &elemSize)
{
	size_t	nbElem = PmergeMe::size / elemSize;
	size_t	pairSize = elemSize * 2;
	size_t	nbPair = PmergeMe::size / pairSize;
	int		hasStray = (nbElem % 2 != 0) ? 1 : 0;

	// if there is only 1 element, return
	if (nbElem == 1) {
		return ;
	}
	
	iterator	begin = container.begin();
	iterator	end = container.end();

	// iterate through the pairs
	for (iterator it = begin; it < begin + (nbPair * pairSize); it += pairSize)
	{
		if (*(it + elemSize - 1) > *(it + pairSize - 1)) {
			swapPair(it, elemSize);
		}
	}

	// call the function recursively
	sort(container, pairSize);

	iterator	tmpBegin = PmergeMe::tmp->begin();
	iterator	tab[nbPair + hasStray];

	//insert biggest value of each pair in the main chain
	for(size_t i = 0; i < nbPair; i++)
	{
		PmergeMe::insert(begin + elemSize + (pairSize * i), tmpBegin + (i * elemSize), elemSize);
		tab[i] = tmpBegin + (elemSize * i) + elemSize;
	}
	if (hasStray) {
		tab[nbPair] = tab[nbPair - 1];
	}

	//insert first element in the main chain
	insert(begin, tmpBegin, elemSize);
	
	iterator	pend;
	iterator	low;
	iterator	high;
	iterator	insertionPoint;
	size_t		j;
	size_t		pos = 1;

	for (int k = 0; k >= 0; k++)
	{
		j = jacobsthal[k];
		if (nbPair + hasStray < j) {
			j = nbPair + hasStray;
			k = -2;
		}
		for (size_t diff = j; diff > pos; diff--)
		{
			// define the element to insert and the search area
			pend = begin + ((diff - 1) * pairSize);
			low = tmpBegin;
			high = tab[diff - 1];
			high -= (diff - 1 < nbPair) ? elemSize : 0;

			// search where to insert the pend element with a binary search
			insertionPoint = binarySearch(*(pend + elemSize - 1), low, high, elemSize);

			for (size_t i = 0; i < nbPair + hasStray; i++)
			{
				if (tab[i] >= insertionPoint) {
					tab[i] += elemSize;
				}
			}

			// insert the element at the right place
			insert(pend, insertionPoint, elemSize);
		}
		pos = j;
	}

	// insert the remaining numbers at the end of the chain
	for (size_t i = nbElem * elemSize; begin + i < end; i++) {
		*(tmpBegin + i) = *(begin + i);
	}

	container = *tmp;
}

template <typename Container>
void	PmergeMe<Container>::mergeInsertionSort(Container &container)
{
	PmergeMe::size = container.size();
	PmergeMe::tmp = new Container(PmergeMe::size);
	size_t	elemSize = 1;
	
	sort(container, elemSize);

	PmergeMe::size = 0;
	delete PmergeMe::tmp;
	PmergeMe::tmp = NULL;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
