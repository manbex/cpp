#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm(AForm const &);
		AForm(std::string const &, int const &, int const&);
		virtual ~AForm();
		AForm	&operator=(AForm const &);

		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		bool			isSigned() const;

		void			beSigned(Bureaucrat const &);
		void			execute(Bureaucrat const &executor) const;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Form not signed");
				}
		};

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_signed;

		virtual	void	executeForm() const = 0;
};

std::ostream	&operator<<(std::ostream &, AForm const &);

#endif
