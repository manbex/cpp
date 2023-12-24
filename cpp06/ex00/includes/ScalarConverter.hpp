#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP 

#include <string>
#include <iostream>
#include <sstream>
#include <climits>

class	ScalarConverter
{
	public:
		static void	convert(std::string const &arg);

	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &cpy);
		~ScalarConverter();
		ScalarConverter	&operator=(ScalarConverter const &cpy);

		typedef enum	e_type
		{
			LITERAL,
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			INVALID
		}	type;

		static type		findType(std::string const &arg);
};

#endif
