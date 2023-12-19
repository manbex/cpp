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
		Form(Form const &);
		Form(std::string const &, int const &, int const &);
		~Form();
		Form	&operator=(Form const &);

		std::string	getName() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		bool		isSigned() const;

		void		beSigned(Bureaucrat &);

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
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_signed;
};

std::ostream	&operator<<(std::ostream &, Form const &);

#endif
