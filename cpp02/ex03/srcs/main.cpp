#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	test(Point const &a, Point const &b, Point const &c, Point const &p)
{
	std::cout << "testing with p(" << p.getX() << ", " << p.getY() << "): ";

	if (bsp(a, b, c, p))
		std::cout << "Success" << std::endl;
	else
		std::cout << "Failure" << std::endl;
}

int	main()
{
	Point a(-3, -1);
	Point b(3, 5);
	Point c(5.5, 0.5);
	Point p1(2, 2);
	Point p2(10, 15);
	Point p3(-3, -1);

	std::cout << "Triangle coordinates: a(" << a.getX() << ", " << a.getY() << ")\n";
	std::cout << "                      b(" << b.getX() << ", " << b.getY() << ")\n";
	std::cout << "                      c(" << c.getX() << ", " << c.getY() << ")\n" << std::endl;

	test(a, b, c, p1);
	test(a, b, c, p2);
	test(a, b, c, p3);
	return (0);
}
