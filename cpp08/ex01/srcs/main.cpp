#include "Span.hpp"

int	main()
{
	Span	span(5);

	try
	{
		span.addNumber(-60);
		span.addNumber(0);
		span.addNumber(156);
		span.addNumber(15);
		span.addNumber(10);
		span.addNumber(6);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	span.print();
	std::cout << std::endl;

	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	return (0);
}
