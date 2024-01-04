#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>

void	identify(Base *p)
{
	A	*A_ptr = dynamic_cast<A *>(p);
	B	*B_ptr = dynamic_cast<B *>(p);
	C	*C_ptr = dynamic_cast<C *>(p);

	if (A_ptr)
		std::cout << "A" << std::endl;
	if (B_ptr)
		std::cout << "B" << std::endl;
	if (C_ptr)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&A_ref = dynamic_cast<A &>(p);
		static_cast<void>(A_ref);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		B	&B_ref = dynamic_cast<B &>(p);
		static_cast<void>(B_ref);
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		C	&C_ref = dynamic_cast<C &>(p);
		static_cast<void>(C_ref);
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{}
}

Base	*generate(void)
{
	Base	*p;

	struct timeval	tv;
	gettimeofday(&tv, NULL);
	srand(tv.tv_usec);

	int	value = rand() % 3;
	if (value == 0)
		p = new A();
	if (value == 1)
		p = new B();
	if (value == 2)
		p = new C();
	return (p);
}

int	main()
{
	Base	*p = generate();

	identify(p);
	identify(*p);
	delete p;
	return (0);
}
