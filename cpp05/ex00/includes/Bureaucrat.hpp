#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat(Bureaucrat const &);
		Bureaucrat(std::string const &, int const &);
		~Bureaucrat();
		Bureaucrat			&operator=(Bureaucrat const &);

		std::string			getName() const;
		int					getGrade() const;

		void				decreaseGrade();
		void				increaseGrade();

		class				GradeTooHighException;
		class				GradeTooLowException;

	private:
		std::string const	_name;
		int					_grade;

		Bureaucrat();
};

class	Bureaucrat::GradeTooHighException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class	Bureaucrat::GradeTooLowException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

std::ostream	&operator<<(std::ostream &, Bureaucrat const &);

#endif
