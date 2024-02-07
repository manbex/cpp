#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(Bureaucrat const &cpy): _name(cpy._name), _grade(cpy._grade)
{}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade): _name(name), _grade(grade)
{
	std::cout << "Initialise bureaucrat "<< this->_name << " with grade " << grade <<  std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat		&Bureaucrat::operator=(Bureaucrat const &cpy)
{
	this->_grade = cpy._grade;
	return (*this);
}

std::string		Bureaucrat::getName() const
{
	return (this->_name);
}

int				Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void			Bureaucrat::increaseGrade()
{
	std::cout << this->_name << " increases grade" << std::endl;
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void			Bureaucrat::decreaseGrade()
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

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}
