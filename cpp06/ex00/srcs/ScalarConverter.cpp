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
	long int			res = 0;

	tmp << arg;
	tmp >> res;
	if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
	{
		std::cout << "Impossible conversion: int overflows" << std::endl;
		return ;
	}
	int		i = static_cast<int>(res);
	float	f = static_cast<float>(i);
	double	d = static_cast<double>(i);

	if (i > std::numeric_limits<char>::min() && i < std::numeric_limits<char>::max())
	{
		char	c = static_cast<char>(i);
		if (isPrintable(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << i << std::endl;
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

static void		convertFloat(double const &f)
{
	double	d = static_cast<double>(f);

	if (f > std::numeric_limits<char>::min() && f < std::numeric_limits<char>::max())
	{
		char	c = static_cast<char>(f);
		if (isPrintable(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (f == std::numeric_limits<float>::infinity()
		|| f == -std::numeric_limits<float>::infinity()
		|| f > std::numeric_limits<int>::max()
		|| f < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int	i = static_cast<int>(f);
		std::cout << "int: " << i << std::endl;
	}
	if (f < -99999 || f > 99999 || f - static_cast<int>(f) != 0)
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

static void		convertDouble(double const &d)
{
	float	f = static_cast<float>(d);

	if (d > std::numeric_limits<char>::min() && d < std::numeric_limits<char>::max())
	{
		char	c = static_cast<char>(d);
		if (isPrintable(c))
			std::cout << "char: " << c << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (d == std::numeric_limits<double>::infinity()
		|| d == -std::numeric_limits<double>::infinity()
		|| d != d
		|| d > std::numeric_limits<int>::max()
		|| d < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int	i = static_cast<int>(d);
		std::cout << "int: " << i << std::endl;
	}
	if (d < -99999 || d > 99999 || d - static_cast<int>(d) != 0)
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

static void		convertNumber(std::string const &arg)
{
	int			sign = 1;
	int			size = arg.size();
	int			i = 0;
	long double	res = 0;

	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (arg[i] != '.')
	{
		res = (res * 10) + (arg[i] - '0');
		i++;
	}
	i++;
	float	n = 10;
	while (i < size && arg[i] != 'f')
	{
		res += static_cast<long double>(arg[i] - '0') / n;
		n *= 10;
		i++;
	}
	res *= sign;
	if (arg[size - 1] == 'f')
		convertFloat(static_cast<float>(res));
	else
		convertDouble(static_cast<double>(res));
}

static void		convertDecimal(std::string const &arg)
{
	if (!arg.compare("nan"))
		convertDouble(std::numeric_limits<double>::quiet_NaN());
	else if (!arg.compare("+inf"))
		convertDouble(std::numeric_limits<double>::infinity());
	else if (!arg.compare("-inf"))
		convertDouble(-std::numeric_limits<double>::infinity());
	else if (!arg.compare("+inff"))
		convertDouble(std::numeric_limits<float>::infinity());
	else if (!arg.compare("-inff"))
		convertDouble(-std::numeric_limits<float>::infinity());
	else
		convertNumber(arg);
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
	if (isTypeChar(arg))
		return (CHAR);
	if (isTypeInt(arg))
		return (INT);
	if (isTypeFloat(arg) || isTypeLiteral(arg))
		return (DECIMAL);
	return (INVALID);
}

void			ScalarConverter::convert(std::string const &arg) 
{
	type	type = ScalarConverter::findType(arg);

	if (type == CHAR)
		convertChar(arg);
	else if (type == INT)
		convertInt(arg);
	else if (type == DECIMAL)
		convertDecimal(arg);
	else if (type == INVALID)
		std::cout << "Invalid data type" << std::endl;
}
