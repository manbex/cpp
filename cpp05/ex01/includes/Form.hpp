/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:30:39 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:30:42 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(Form const &);
		Form(std::string const &, int const &, int const &);
		~Form();
		Form	&operator=(Form const &);

		std::string			getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;

		void				beSigned(Bureaucrat &);

		class				GradeTooHighException;
		class				GradeTooLowException;

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_signed;

		Form();
};

class	Form::GradeTooHighException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class 	Form::GradeTooLowException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};


std::ostream	&operator<<(std::ostream &, Form const &);

#endif
