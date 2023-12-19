#include "Form.hpp"

Form::Form():
	_name(""),
	_gradeToSign(150), 
	_gradeToExecute(150),
	_signed(false)
{}

Form::Form(const Form &cpy):
	_name(cpy._name),
	_gradeToSign(cpy._gradeToSign), 
	_gradeToExecute(cpy._gradeToExecute),
	_signed(cpy._signed)
{}

Form::Form(const std::string &name, const int &gradeToSign, const int &gradeToExecute): 
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	std::cout << "Initialise form "<< this->_name <<  std::endl;

	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{}

Form			&Form::operator=(const Form &cpy)
{
	(void)cpy;
	return (*this);
}

std::string		Form::getName()
{
	return (this->_name);
}

int				Form::getGradeToSign()
{
	return (this->_gradeToSign);
}

int				Form::getGradeToExecute()
{
	return (this->_gradeToExecute);
}

bool			Form::isSigned()
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &o, Form &Form)
{
	o << Form.getName() << ", grade to sign " << Form.getGradeToSign() << ", grade to execute " \
	<< Form.getGradeToExecute();
	if (Form.isSigned())
		o << ", signed";
	else
		o << ", not signed";
	return (o);
}
