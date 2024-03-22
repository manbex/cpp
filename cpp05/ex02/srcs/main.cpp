/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:32:00 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:32:06 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat Oscar("Oscar", 140);

	std::cout << std::endl;
	ShrubberyCreationForm form1("home");
	std::cout << form1 << std::endl;
	Oscar.executeForm(form1);

	std::cout << std::endl;
	Oscar.signForm(form1);
	Oscar.executeForm(form1);

	std::cout << std::endl;
	Oscar.setGrade(1);
	Oscar.executeForm(form1);

	std::cout << std::endl;
	RobotomyRequestForm form2("C-3PO");
	Oscar.signForm(form2);
	Oscar.executeForm(form2);

	std::cout << std::endl;
	PresidentialPardonForm form3("War criminal");
	Oscar.signForm(form3);
	Oscar.executeForm(form3);

	return (0);
}
