#include "Span.hpp"

Span::Span(unsigned int const &size): _size(size)
{
	std::cout << "creating Span of size " << size << std::endl;
}

Span::Span(Span const &cpy): _size(cpy._size)
{
	*this = cpy;
}

Span	&Span::operator=(Span const &cpy)
{
	this->_content.assign(cpy._content.begin(), cpy._content.end());
	if (this->_content.size() > this->_size) {
		this->_content.resize(this->_size);
	}
	return (*this);
}

Span::~Span()
{}

void			Span::addNumber(int const &value)
{
	if (this->_content.size() >= this->_size) {
		throw Span::SpanFullException();
	}
	std::cout << "adding number " << value << std::endl;
	this->_content.push_back(value);
}

void			Span::fill(int const &value)
{
	std::cout << "filling span with number " << value << std::endl;
	size_t	size = this->_content.size();
	while (size < this->_size) {
		this->_content.push_back(value);
	}
}

static int		diff(int const &n1, int const &n2)
{
	int res = n1 - n2;
	return (res > 0 ? res : -res);
}

unsigned int	Span::shortestSpan() const
{
	if (this->_content.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	std::list<int>::const_iterator	it1 = this->_content.begin();
	std::list<int>::const_iterator	ite = this->_content.end();
	std::list<int>::const_iterator	it2;
	int								res = std::numeric_limits<int>::max();

	for (; it1 != ite; it1++)
	{
		for (it2 = it1; it2 != ite; it2++)
		{
			if (it2 == it1) {
				it2++;
			}
			if (it2 == ite) {
				break ;
			}
			int tmp = diff(*it1, *it2);
			res = tmp < res ? tmp : res;
			if (res == 0) {
				return (res);
			}
		}
	}
	return (res);
}

unsigned int	Span::longestSpan() const
{
	if (this->_content.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	std::list<int>::const_iterator min;
	std::list<int>::const_iterator max;

	min = std::min_element(this->_content.begin(), this->_content.end());
	max = std::max_element(this->_content.begin(), this->_content.end());
	return (diff(*min, *max));
}

static void		print_value(int const &n)
{
	std::cout << n << std::endl;
}

void			Span::print() const
{
	std::for_each(this->_content.begin(), this->_content.end(), print_value);
}
