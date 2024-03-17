#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(): std::stack<T, Container>()
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(MutantStack<T, Container> const &cpy): std::stack<T, Container>(cpy)
{
	*this = cpy;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

template<typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(MutantStack<T, Container> const &cpy)
{
	std::stack<T, Container>::operator=(cpy);
	return (*this);
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<typename T, typename Container>
typename Container::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}

#endif
