/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:38:21 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/18 11:51:50 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

int	get_info(int selector, std::string prompt, Contact &contact)
{
	std::string	buf;

	while (1)
	{
		std::cout << prompt;
		std::getline(std::cin, buf);
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
		if (!buf.empty() && buf.find_first_of("\t\n\r\v\f") == std::string::npos \
		&& ((!prompt.compare("phone number: ") && \
		buf.find_first_not_of("0123456789") == std::string::npos) \
		|| prompt.compare("phone number: ")) && (!prompt.compare("darkest secret: ") \
		|| (prompt.compare("darkest secret: ") && buf.find_first_of(" ") == std::string::npos)))
		{
			if (selector == 0)
				contact.set_first_name(buf);
			else if (selector == 1)
				contact.set_last_name(buf);
			else if (selector == 2)
				contact.set_nickname(buf);
			else if (selector == 3)
				contact.set_phone_number(buf);
			else
				contact.set_darkest_secret(buf);
			return (0);
		}
	}
}

int	PhoneBook::add()
{
	std::string	prompt[] = {"first name: ", "last name: ", "nickname: ", "phone number: ", "darkest secret: "};
	for (int i = 7; i > 0; i--)
		this->_contact[i] = this->_contact[i - 1];
	for (int i = 0; i < 5; i++)
		if (get_info(i, prompt[i], this->_contact[0]))
			return (1);
	return (0);
}

void	print_info(std::string info)
{
	if (info.size() < 10)
	{
		std::cout << std::setw(10) << std::right << info;
		return ;
	}
	std::cout << info.substr(0, 9) << ".";
}

int	PhoneBook::search() const
{
	std::string	buf;
	int			n;

	if (this->_contact[0].empty())
		return (0);
	for (int i = 0; i < 8; i++)
	{
		if (!this->_contact[i].empty())
		{
			std::cout << "         " << i + 1 << "|";
			print_info(this->_contact[i].get_first_name());
			std::cout << "|";
			print_info(this->_contact[i].get_last_name());
			std::cout << "|";
			print_info(this->_contact[i].get_nickname());
			std::cout << std::endl;
		}
	}
	std::cout << "Type the index of the contact you want to display: ";
	std::getline(std::cin, buf);
	if (std::cin.eof())
		return (std::cout << std::endl, 1);
	if (buf.size() == 1 && buf.find_first_not_of("0123456789"))
	{
		n = *buf.c_str() - '0' - 1;
		if (n >= 0 && n < 8 && !this->_contact[n].empty())
		{
			std::cout << "first name:      | " << this->_contact[n].get_first_name() << std::endl;
			std::cout << "last name:       | " << this->_contact[n].get_last_name() << std::endl;
			std::cout << "nickname:        | " << this->_contact[n].get_nickname() << std::endl;
			std::cout << "phone number:    | " << this->_contact[n].get_phone_number() << std::endl;
			std::cout << "darkeset secret: | " << this->_contact[n].get_darkest_secret() << std::endl;
		}
	}
	return (0);
}
