#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern intern;
	AForm	*form1 = intern.makeForm("randomName", "target");
	std::cout << std::endl;
	AForm	*form2 = intern.makeForm("ShrubberyCreationForm", "home");
	std::cout << std::endl;
	AForm	*form3 = intern.makeForm("RobotomyRequestForm", "C-3PO");
	std::cout << std::endl;
	AForm	*form4 = intern.makeForm("PresidentialPardonForm", "Criminal");

	delete(form2);
	delete(form3);
	delete(form4);

	(void)form1;
	(void)form2;
	(void)form3;
	(void)form4;
	return (0);
}
