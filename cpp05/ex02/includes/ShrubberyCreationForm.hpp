#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <fstream>

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm(std::string const &);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);

		std::string	getTarget() const;

		virtual void	executeForm() const;

		class FileErrorException: public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error while opening file");
				}
		};

	private:
		std::string const	_target;
};

#endif

