#ifndef __POINT_H__
# define __POINT_H__

#include "Fixed.hpp"

class	Point
{
	public:
		Point();
		Point(Point const &);
		Point(float const, float const);
		~Point();
		Point	&operator=(Point const &);

		Fixed	getX() const;
		Fixed	getY() const;
		
	private:
		Fixed const	_x;
		Fixed const	_y;
};

#endif
