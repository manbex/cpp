/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:49:57 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/14 12:50:25 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string buf;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, buf);
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
		else if (buf.compare("EXIT") == 0)
			return (0);
		else if (buf.compare("ADD") == 0)
		{
			if (phonebook.add())
				return (1);
		}
		else if (buf.compare("SEARCH") == 0)
		{
			if (phonebook.search())
				return (1);
		}
	}
	return (0);
}
