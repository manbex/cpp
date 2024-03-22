/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:38:12 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:38:13 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		ShrubberyCreationForm(ShrubberyCreationForm const &);
		ShrubberyCreationForm(std::string const &);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &);

		std::string				getTarget() const;

		virtual void			executeForm() const;

		class					FileErrorException;

	private:
		std::string const		_target;

		ShrubberyCreationForm();
};

class	ShrubberyCreationForm::FileErrorException: public std::exception
{
	public:
		virtual const char	*what() const throw();
};

#endif
