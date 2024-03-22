/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:33:26 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:33:27 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(RobotomyRequestForm const &);
		RobotomyRequestForm(std::string const &);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &);

		std::string			getTarget() const;

		virtual void		executeForm() const;

	private:
		std::string const	_target;

		RobotomyRequestForm();
};

#endif

