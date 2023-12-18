#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Form	form1("formulaire 1", -5, 9);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Form	form2("formulaire 2", 5, 160);
		std::cout << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Oscar("Oscar", 5);
		Form	form3("formulaire 3", 5, 9);
		std::cout << form3 << std::endl;
		Oscar.signForm(form3);
		std::cout << form3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Thomas("Thomas", 6);
		Form	form4("formulaire 4", 5, 9);
		std::cout << form4 << std::endl;
		Thomas.signForm(form4);
		std::cout << form4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
