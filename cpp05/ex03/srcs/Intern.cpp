/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:36:54 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:36:56 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{}

Intern::Intern(Intern const &cpy)
{
	(void)cpy;
}

Intern::~Intern()
{}

Intern			&Intern::operator=(Intern const &cpy)
{
	(void)cpy;
	return (*this);
}

static AForm	*makeShrubberyCreationForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*makeRobotomyRequestForm(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makePresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

Intern::FormType	Intern::type[] =
{
	{"ShrubberyCreationForm", &makeShrubberyCreationForm},
	{"RobotomyRequestForm", &makeRobotomyRequestForm},
	{"PresidentialPardonForm", &makePresidentialPardonForm}
};

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	for (int i = 0; i < 3; i++)
	{ 
		if (type[i].name == name)
		{
			std::cout << "Intern creates "<< name << std::endl;
			return (type[i].func(target));
		}
	}
	std::cerr << "Intern couldn't create " << name << ": invalid form type" << std::endl;
	return (NULL);
}
