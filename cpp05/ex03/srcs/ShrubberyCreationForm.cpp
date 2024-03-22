/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:37:46 by mbenicho          #+#    #+#             */
/*   Updated: 2024/03/22 13:37:48 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy):
	AForm(cpy),
	_target(cpy._target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):
	AForm("Shrubbery creation form", 145, 137),
	_target(target)
{
	std::cout << "Shrubbery creation form initialised with target " << target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cpy)
{
	(void)cpy;
	return (*this);
}

std::string				ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void					drawTree(std::ofstream &file)
{
	file << "              _{\\ _{\\{\\/}/}/}__\n";
	file << "             {/{/\\}{/{/\\}(\\}{/\\} _\n";
	file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\} _\n";
	file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
	file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
	file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
	file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
	file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
	file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n";
	file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
	file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
	file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
	file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
	file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
	file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\n";
	file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
	file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n";
	file << "              {){/ {\\/}{\\/} \\}\\}\n";
	file << "              (_)  \\.-'.-/\n";
	file << "          __...--- |'-.-'| --...__\n";
	file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n";
	file << " -\"    ' .  . '    |.'-._| '  . .  '   \n";
	file << " .  '-  '    .--'  | '-.'|    .  '  . '\n";
	file << "          ' ..     |'-_.-|\n";
	file << "  .  '  .       _.-|-._ -|-._  .  '  .\n";
	file << "              .'   |'- .-|   '.\n";
	file << "  ..-'   ' .  '.   `-._.-'   .'  '  - .\n";
	file << "   .-' '        '-._______.-'     '  .\n";
	file << "        .      ~,\n";
	file << "    .       .        .    ' '-.\n";
}

void					ShrubberyCreationForm::executeForm() const
{
	std::string		filename = this->_target + "_shrubbery";
	std::ofstream	file;

	file.open(filename.c_str(), std::ios::out);
	if (!file.is_open())
	{
		throw ShrubberyCreationForm::FileErrorException();
	}
	drawTree(file);
	file.close();
}

const char				*ShrubberyCreationForm::FileErrorException::what() const throw()
{
	return ("Error while opening file");
}
