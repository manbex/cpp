#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form();
		Form(Form &);
		Form(std::string const &, int const &, int const &);
		~Form();
		Form	&operator=(Form &);

		std::string	getName();
		int			getGradeToSign();
		int			getGradeToExecute();
		bool		isSigned();

		void	beSigned(Bureaucrat &);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade too high");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Grade too low");
				}
		};

	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &, Form &);

#endif
