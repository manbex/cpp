#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
	(void)cpy;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &cpy)
{
	(void)cpy;
	return (*this);
}

static bool		isNum(char const &c)
{
	if (c < '0'|| c > '9')
		return (false);
	return (true);
}

static bool		isTypeChar(std::string const &arg)
{
	if (arg.size() != 1 || isNum(arg[0]))
		return (false);
	return (true);
}

static bool		isTypeInt(std::string const &arg)
{
	int	i = 0;
	int	size = arg.size();

	if (arg[0] == '-')
		i++;
	while (i < size)
	{
		if (!isNum(arg[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool		isTypeFloat(std::string const &arg)
{
	int	i = 0;
	int	size = arg.size();

	if (arg[i] == '-')
		i++;
	while (true)
	{
		if (i == size)
			return (false);
		if (!isNum(arg[i]))
			break ;
		i++;
	}
	if (arg[i] != '.' || ++i == size || arg[i] == 'f')
		return (false);
	while (true)
	{
		if (i == size)
			return (true);
		if (!isNum(arg[i]))
			break ;
		i++;
	}
	if (arg[i] == 'f')
		i++;
	if (i != size)
		return (false);
	return (true);
}

ScalarConverter::type	ScalarConverter::findType(std::string const &arg)
{
	if (isTypeChar(arg))
			return (CHAR);
	if (isTypeInt(arg))
			return (INT);
	if (isTypeFloat(arg))
	{
		if (arg[arg.size() - 1] == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	return (INVALID);
}

void			ScalarConverter::convert(std::string const &arg) 
{
	type	type = ScalarConverter::findType(arg);
	std::cout << type << std::endl;
}
