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

	Array<std::string>	c = Array<std::string>(5);
	std::cout << "String array c initialized with size 5" << std::endl;
	try
	{
		c[3] = "\"This is a test\"";
		std::cout << "\"This is a test\" assigned to c[3]" << std::endl;
		std::cout << "c[3] = " << c[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
