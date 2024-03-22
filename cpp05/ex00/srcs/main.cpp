/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:25:53 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:25:57 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	Oscar("Oscar", 5);
		std::cout << Oscar << std::endl;
		Oscar.increaseGrade();
		std::cout << Oscar << std::endl;
		Oscar.decreaseGrade();
		std::cout << Oscar << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Samir("Samir", -5);
		std::cout << Samir << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Thomas("Thomas", 162);
		std::cout << Thomas << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Mathieu("Mathieu", 1);
		std::cout << Mathieu << std::endl;
		Mathieu.increaseGrade();
		std::cout << Mathieu << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat	Ashkan("Ashkan", 150);
		std::cout << Ashkan << std::endl;
		Ashkan.decreaseGrade();
		std::cout << Ashkan << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
