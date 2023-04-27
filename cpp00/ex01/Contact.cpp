#include "Contact.hpp"

Contact::Contact(): _empty(1)
{
}

Contact::~Contact()
{
}

std::string	Contact::get_first_name() const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name() const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname() const
{
	return (this->_nickname);
}
std::string	Contact::get_phone_number() const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret() const
{
	return (this->_darkest_secret);
}

void	Contact::set_first_name(std::string str)
{
	this->_empty = 0;
	this->_first_name = str;
}
void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->_phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
}

int	Contact::empty() const
{
	return (this->_empty);
}
