#include "Array.hpp"

int	main()
{
	Array<int>	*a = new Array<int>();
	std::cout << "Int array a initialized with default constructor" << std::endl;
	std::cout << "a size: " << a->size() << std::endl;
	std::cout << std::endl;

	Array<int>	*b = new Array<int>(10);
	std::cout << "Int array b initialized with size 10" <<std::endl;
	std::cout << "b size: " << b->size() << std::endl;
	std::cout << std::endl;

	try
	{
		(*b)[0] = 42;
		std::cout << "42 assigned to b[0]" << std::endl;
		std::cout << "b[0] = " << (*b)[0] << std::endl;
		std::cout << std::endl;

		*a = *b;
		std::cout << "a = b" << std::endl;

		std::cout << "Delete b" << std::endl;
		delete b;
	
		std::cout << "a size: " << a->size() << std::endl;
		std::cout << "a[0] = " << (*a)[0] << std::endl;
		std::cout << std::endl;

		std::cout << "Trying to access a[10]" << std::endl;
		(*a)[10] = 0;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete a;

	Array<int>	c(12);
	std::cout << "Int array c initialized with size 12" <<std::endl;
	std::cout << "c size: " << c.size() << std::endl;
	std::cout << "Int array d initialized as a copy of d" <<std::endl;
	Array<int>	d(c);
	std::cout << "d size: " << d.size() << std::endl;
	std::cout << std::endl;

	Array<std::string>	e = Array<std::string>(5);
	std::cout << "String array e initialized with size 5" << std::endl;
	try
	{
		e[3] = "\"This is a test\"";
		std::cout << "\"This is a test\" assigned to e[3]" << std::endl;
		std::cout << "e[3] = " << e[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
