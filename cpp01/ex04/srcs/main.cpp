/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 16:31:05 by mbenicho          #+#    #+#             */
/*   Updated: 2023/06/26 17:08:21 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

std::string	read_file(std::ifstream &infile)
{
	std::string		str;
	std::string		buf;

	while (std::getline(infile, buf))
		str +=  buf + "\n";
	return (str);
}

std::string	replace(std::string &str, std::string s1, std::string s2)
{
	std::string	dest;
	int			i = 0;
	size_t		len;
	(void)s2;

	for (int size = str.size(); i < size;)
	{
		len = str.find(s1, i);
		if (len != std::string::npos)
		{
			dest += str.substr(i, len - i) + s2;
			i = len + s1.size();
		}
		else
		{
			dest+= str.substr(i);
			break ;
		}
	}
	return (dest);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		filename;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (0);
	}
	if (*argv[1] == 0 || *argv[2] == 0)
	{
		std::cout << "Error: invalid arguments "<< std::endl;
		return (1);
	}
	filename = argv[1];
	infile.open(filename.c_str(), std::ios::in);
	if (!infile.is_open())
	{
		std::cout << "Error: " << filename << ": failed to open" << std::endl;
		return (1);
	}
	filename += ".replace";
	outfile.open(filename.c_str(), std::ios::out);
	if (!outfile.is_open())
	{
		std::cout << "Error: " << filename << ": failed to open" << std::endl;
		infile.close();
		return (1);
	}
	str = read_file(infile);
	str = replace(str, argv[2], argv[3]);
	outfile << str;
	infile.close();
	outfile.close();
	return (0);
}
