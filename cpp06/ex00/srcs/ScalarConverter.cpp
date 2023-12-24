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

static bool	isPrintable(char const &c)
{
	if (c < 32 || c > 126)
		return (false);
	return (true);
}

static void		convertChar(std::string const &arg)
{
	char	c = arg[0];
	int		i = static_cast<int>(c);
	float	f = static_cast<float>(c);
	double	d = static_cast<double>(c);

	if (isPrintable(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static void		convertInt(std::string const &arg)
{
	std::stringstream	tmp;
	long int			l = 0;

	tmp << arg;
	tmp >> l;
	if (l < INT_MIN || l > INT_MAX)
	{
		std::cout << "Impossible conversion: int overflows" << std::endl;
		return ;
	}
	int		i = static_cast<int>(l);
	char	c = static_cast<char>(i);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << l << std::endl;
	if (i < -999999 || i > 999999)
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
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

static bool	isTypeLiteral(std::string const &arg)
{
	if (!arg.compare("nan")
		|| !arg.compare("+inf")
		|| !arg.compare("-inf")
		|| !arg.compare("-inff")
		|| !arg.compare("+inff"))
		return (true);
	return (false);
}

ScalarConverter::type	ScalarConverter::findType(std::string const &arg)
{
	if (isTypeLiteral(arg))
		return (LITERAL);
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

	if (type == CHAR)
		convertChar(arg);
	if (type == INT)
		convertInt(arg);
	else if (type == INVALID)
		std::cout << "Invalid data type" << std::endl;
}
