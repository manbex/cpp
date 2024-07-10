#include "Span.hpp"

int	main()
{
	Span	span(5);
	std::cout << std::endl;
	
	try {
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		span.addNumber(6);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::list<int>	list(10000, 69);
	list.push_back(-351);
	Span	span2(list.size());
	span2.addNumber(list.begin(), list.end());
	std::cout << std::endl;

	try
	{
		std::cout << "shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "longest span: " << span2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
