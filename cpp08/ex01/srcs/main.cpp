#include "Span.hpp"

int	main()
{
	Span	span(5);
	std::cout << std::endl;
	
	try {
		std::cout << span.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
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
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::vector<int>	tmp(10000, 15);
	tmp.push_back(-405);
	Span	span2(tmp.size());
	span2.addNumber(tmp.begin(), tmp.end());
	std::cout << std::endl;

	try
	{
		std::cout << "shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "longest span: " << span2.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
