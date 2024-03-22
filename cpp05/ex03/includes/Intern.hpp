/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:38:05 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:38:06 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern(Intern const &cpy);
		~Intern();
		Intern	&operator=(Intern const &cpy);

		AForm	*makeForm(std::string const &, std::string const &);

	private:
		typedef struct
		{
			std::string const	name;
			AForm				*(*func)(std::string const &);
		}	FormType;

		static FormType			type[];
};

#endif
