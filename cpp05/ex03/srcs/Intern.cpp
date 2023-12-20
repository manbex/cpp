#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &cpy)
{
	(void)cpy;
}

Intern::~Intern()
{}

Intern	&Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return (*this);
}

static AForm	*makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

typedef AForm	*(*f)(std::string const &);
typedef struct	{std::string const name; f func;} Type;

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	Type	type[] =
	{
		{"ShrubberyCreationForm", &makeShrubberyCreationForm},
		{"RobotomyRequestForm", &makeRobotomyRequestForm},
		{"PresidentialPardonForm", &makePresidentialPardonForm}
	};
	
	for (int i = 0; i < 3; i++)
	{ 
		if (type[i].name == name)
		{
			std::cout << "Intern creates "<< name << std::endl;
			return (type[i].func(target));
		}
	}
	std::cerr << "Intern couldn't create " << name << ": invalid form type" << std::endl;
	return (NULL);
}

