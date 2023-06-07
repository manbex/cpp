#include "Point.hpp"

Fixed	area(Fixed const &ax, Fixed const &ay, Fixed const &bx, Fixed const &by, Fixed const &cx, Fixed const &cy)
{
	Fixed area(((ax * (by - cy)) + (bx * (cy - ay)) + (cx * (ay - by))) / 2);
	if (area < 0)
		area = area * -1;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed const ax = a.getX(); Fixed const bx = b.getX(); Fixed const cx = c.getX(); Fixed const px = point.getX();
	Fixed const ay = a.getY(); Fixed const by = b.getY(); Fixed const cy = c.getY(); Fixed const py = point.getY();

	Fixed ABC = area(ax, ay, bx, by, cx, cy);
	Fixed PAB = area(ax, ay, bx, by, px, py);
	Fixed PAC = area(ax, ay, px, py, cx, cy);
	Fixed PBC = area(px, py, bx, by, cx, cy);

	if (PAB == 0 || PBC == 0 || PAC == 0)
		return (false);
	return (PAB + PAC + PBC == ABC);
}
