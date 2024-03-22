/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:32:38 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:32:40 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy):
	AForm(cpy),
	_target(cpy._target)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):
	AForm("Presidential pardon form", 145, 137),
	_target(target)
{
	std::cout << "Presidential pardon form initialised with target " << target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string				PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void					PresidentialPardonForm::executeForm() const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
