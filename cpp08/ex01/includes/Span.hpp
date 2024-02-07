#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <utility>
#include <limits>

class	Span
{
	public:
		Span(unsigned int const &);
		Span(Span const &);
		Span	&operator=(Span const &);
		~Span();

		void			addNumber(int const &);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			print() const;
		void			fill(int const &value);

		class			SpanFullException;
		class			NotEnoughElementsException;

	private:
		unsigned int const	_size;
		std::list<int>		_content;

		Span();
};

class			Span::SpanFullException: public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Span is full");
		}
};

class			Span::NotEnoughElementsException: public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Not enough elements");
		}
};

#endif
