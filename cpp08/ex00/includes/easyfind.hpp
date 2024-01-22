#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T>
typename T::const_iterator	easyfind(T const &container, int const &value)
{
	typename T::const_iterator	begin = container.begin();
	typename T::const_iterator	end = container.end();
	typename T::const_iterator	it = std::find(begin, end, value);
	return (it);
}

template <typename T>
void	test(T const &container, int const &value)
{
	typename T::const_iterator	it = easyfind<T>(container, value);

	if (it == container.end())
		std::cout << "No match found" << std::endl;
	else
		std::cout << "Value found: " << *it << std::endl;
}

#endif
