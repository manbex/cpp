#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(Point const &cpy): _x(cpy.getX()), _y(cpy.getY())
{
}

Point::Point(float const a, float const b): _x(a), _y(b)
{
}

Point &Point::operator=(Point const &cpy)
{
	(void)cpy;
	return (*this);
}

Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
