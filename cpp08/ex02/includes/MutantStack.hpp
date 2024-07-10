#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <deque>
#include <iostream>
#include <list>

template<typename T, typename Container = std::deque<T> >
class	MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack<T, Container>();
		MutantStack<T, Container>(MutantStack<T, Container> const &cpy);
		virtual ~MutantStack<T, Container>();
		MutantStack<T, Container>	&operator=(MutantStack<T, Container> const &cpy);

		typedef typename Container::iterator	iterator;

		iterator	begin();
		iterator	end();

	private:
};

#include "MutantStack.tpp"

#endif
