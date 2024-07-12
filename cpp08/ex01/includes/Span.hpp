#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <utility>
#include <limits>
#include <list>
#include <vector>

class	Span
{
	public:
		Span(unsigned int const &);
		Span(Span const &);
		Span	&operator=(Span const &);
		~Span();

		void			addNumber(int const &);
		void			fill(int const &value);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			print() const;

		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end);
	
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

template <typename Iterator>
void			Span::addNumber(Iterator begin, Iterator end)
{
	this->_content.insert(this->_content.end(), begin, end);
	if (this->_content.size() >= this->_size) {
		this->_content.resize(this->_size);
	}
}

#endif
