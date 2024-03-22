/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:37:11 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:37:12 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy):
	AForm(cpy),
	_target(cpy._target)
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):
	AForm("Robotomy request form", 72, 45),
	_target(target)
{
	std::cout << "Robotomy request form initialised with target " << target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string			RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void				RobotomyRequestForm::executeForm() const
{
	srand(time(NULL));
	std::cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
