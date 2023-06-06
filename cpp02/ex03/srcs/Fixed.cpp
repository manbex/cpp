#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(Fixed const &cpy)
{
	*this = cpy;
}

Fixed::Fixed(int const value): _value(value << _bits)
{
}

Fixed::Fixed(float const value): _value(roundf(value * (1 << _bits)))
{
}

Fixed &Fixed::operator=(Fixed const &cpy)
{
	this->_value = cpy.getRawBits();
	return (*this);
}

Fixed &Fixed::operator=(float const value)
{
	this->_value = roundf(value * (1 << this->_bits));
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed tmp(this->toFloat() + fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed tmp(this->toFloat() - fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed tmp(this->toFloat() * fixed.toFloat());
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed tmp(this->toFloat() / fixed.toFloat());
	return (tmp);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (*this);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat() const
{
	return (this->_value / (float)(1 << this->_bits));
}

int		Fixed::toInt() const
{
	return (this->_value >> 8);
}

Fixed	Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

Fixed	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed	Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return (o);
}
