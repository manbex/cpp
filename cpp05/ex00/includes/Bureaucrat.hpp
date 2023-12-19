#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &);
		Bureaucrat(const std::string &, const int &);
		~Bureaucrat();
		Bureaucrat		&operator=(const Bureaucrat &);

		std::string		getName();
		int				getGrade();

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
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &, Bureaucrat &);

#endif
