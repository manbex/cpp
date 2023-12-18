#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name(""), _grade(150)
{
}

Bureaucrat::Bureaucrat(Bureaucrat &cpy): _name(cpy.getName()), _grade(cpy.getGrade())
{
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade): _name(name), _grade(grade)
{
	std::cout << "Initialise bureaucrat "<< this->_name << " with grade " << grade <<  std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat &cpy)
{
	this->_grade = cpy.getGrade();
	return (*this);
}

std::string		Bureaucrat::getName()
{
	return (this->_name);
}

int				Bureaucrat::getGrade()
{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade()
{
	std::cout << this->_name << " increases grade" << std::endl;
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decreaseGrade()
{
	std::cout << this->_name << " decreases grade" << std::endl;
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void			Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}
