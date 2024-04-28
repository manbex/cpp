#include "PmergeMe.hpp"

template <typename Container>
void	PmergeMe<Container>::swapElement(iterator &element, size_t &itSize)
{
	int	tmp;

		for (iterator it = element; it != element + (itSize / 2); it++)
	{
		tmp = *it;
		*it = *(it + (itSize / 2));
		*(it + (itSize / 2)) = tmp;
	}
}

template <typename Container>
void	PmergeMe<Container>::sort(Container &container, size_t itSize, size_t const &maxSize)
{
	size_t	size = container.size() / itSize;
	std::cout << "size: " << size << std::endl;
	if (size == 1) {
		return ;
	}
	
	bool	hasStray = (size % 2 != 0);

	iterator	begin = container.begin();
	iterator	end = container.end();

	for (iterator it = begin; it != end; it += itSize)
	{
		if (*(it + (itSize / 2) - 1) > *(it + itSize - 1)) {
			swapElement(it, itSize);
		}
		std::cout << "element: ";
		for (iterator itt = it; itt != it + itSize; itt++)
		{
			std::cout << *itt << ", ";
		}
		std::cout << std::endl;
	}

	if (hasStray)
	{
		std::cout << "stray: ";
		for (iterator itt = begin + (itSize * (size - 1)); itt != end; itt++)
		{
			std::cout << *itt << ", ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	sort(container, itSize * 2, maxSize);
}

template <typename Container>
void	PmergeMe<Container>::mergeInsertionSort(Container &container)
{
	size_t	size = container.size();
	if (size == 1) {
		return ;
	}

	size_t	n = 2;
	while (n != 1073741824)
	{
		if (size >= n) {
			break ;
		}
		n *= 2;
	}

	sort(container, 2, n);
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
