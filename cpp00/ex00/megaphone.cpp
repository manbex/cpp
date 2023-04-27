/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:06:49 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/12 10:08:02 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
		{
			std::string	str = argv[i];
			for (size_t j = 0; str[j]; j++)
			{
				char	c = toupper(str[j]);
				std::cout << c;
			}
		}
	std::cout << std::endl;
	return (0);
}
