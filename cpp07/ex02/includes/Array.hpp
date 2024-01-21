#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>
class	Array
{
	public:
		Array<T>();
		Array<T>(unsigned int const &n);
		Array<T>(Array const &);
		~Array<T>();
		Array<T>	&operator=(Array const &);
		T	&operator[](unsigned int const &i);

		unsigned int	size() const;

		class InvalidIndexException;

	private:
		T				*_array;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
