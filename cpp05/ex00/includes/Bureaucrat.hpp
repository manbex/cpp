#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &);
		Bureaucrat(std::string const &, int const &);
		~Bureaucrat();
		Bureaucrat		&operator=(Bureaucrat const &);

		std::string		getName() const;
		int				getGrade() const;

		void			decreaseGrade();
		void			increaseGrade();

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
		int					_grade;
};

std::ostream	&operator<<(std::ostream &, Bureaucrat const &);

#endif
