/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:33:45 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:33:47 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(PresidentialPardonForm const &);
		PresidentialPardonForm(std::string const &);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &);

		std::string				getTarget() const;

		virtual void			executeForm() const;

	private:
		std::string const		_target;

		PresidentialPardonForm();
};

#endif

