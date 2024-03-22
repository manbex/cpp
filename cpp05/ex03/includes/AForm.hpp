/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:37:58 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:38:00 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
		AForm(AForm const &);
		AForm(std::string const &, int const &, int const&);
		virtual ~AForm();

		AForm				&operator=(AForm const &);

		std::string			getName() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		bool				isSigned() const;

		void				beSigned(Bureaucrat const &);
		void				execute(Bureaucrat const &executor) const;
		virtual	void		executeForm() const = 0;

		class 				GradeTooHighException;
		class 				GradeTooLowException;
		class 				FormNotSignedException;

	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_signed;

		AForm();
};

class AForm::GradeTooHighException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class AForm::GradeTooLowException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

class AForm::FormNotSignedException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

std::ostream	&operator<<(std::ostream &, AForm const &);

#endif
