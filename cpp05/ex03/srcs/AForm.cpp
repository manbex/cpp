#include "AForm.hpp"

AForm::AForm():
	_name(""),
	_gradeToSign(150), 
	_gradeToExecute(150),
	_signed(false)
{}

AForm::AForm(AForm const &cpy):
	_name(cpy._name),
	_gradeToSign(cpy._gradeToSign), 
	_gradeToExecute(cpy._gradeToExecute),
	_signed(cpy._signed)
{}

AForm::AForm(std::string const &name, int const &gradeToSign, int const &gradeToExecute): 
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_signed(false)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{}

AForm			&AForm::operator=(AForm const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string		AForm::getName() const
{
	return (this->_name);
}

int				AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int				AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool			AForm::isSigned() const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	this->executeForm();
}

std::ostream	&operator<<(std::ostream &o, AForm const &AForm)
{
	o << AForm.getName() << ", grade to sign " << AForm.getGradeToSign() << ", grade to execute " \
	<< AForm.getGradeToExecute();
	if (AForm.isSigned())
		o << ", signed";
	else
		o << ", not signed";
	return (o);
}
