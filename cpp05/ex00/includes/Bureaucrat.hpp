/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:26:55 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:27:07 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
