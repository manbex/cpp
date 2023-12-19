#include "Form.hpp"

Form::Form():
	_name(""),
	_gradeToSign(150), 
	_gradeToExecute(150),
	_signed(false)
{}

Form::Form(Form const &cpy):
	_name(cpy._name),
	_gradeToSign(cpy._gradeToSign), 
	_gradeToExecute(cpy._gradeToExecute),
	_signed(cpy._signed)
{}

Form::Form(std::string const &name, int const &gradeToSign, int const &gradeToExecute): 
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

Form			&Form::operator=(Form const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string		Form::getName() const
{
	return (this->_name);
}

int				Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int				Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool			Form::isSigned() const
{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &o, Form const &Form)
{
	o << Form.getName() << ", grade to sign " << Form.getGradeToSign() << ", grade to execute " \
	<< Form.getGradeToExecute();
	if (Form.isSigned())
		o << ", signed";
	else
		o << ", not signed";
	return (o);
}
