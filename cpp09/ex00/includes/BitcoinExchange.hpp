#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include <cstdlib>
#include <cerrno>
#include <limits>
#include <map>

class	BitcoinExchange
{
	public:
		static void		clearDatabase();
		static int		loadDatabase(std::string const &);
		static int		checkInput(char const *);

	private:
		typedef struct
		{
			int	year;
			int month;
			int	day;
		}	date;

		static std::map<std::string, double>	database;
		static std::string						min;
		static std::string						max;

		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &cpy);
		~BitcoinExchange();
		BitcoinExchange	&operator=(BitcoinExchange const &cpy);

		static void			parseData(std::string const &str);
		static int			checkDateFormat(std::string const &str);
		static int			checkValue(std::string const &str);
		static date			strtodate(std::string const &str);
		static int			compareDate(date const &d1, date const &d2);
		static void			parseInput(std::string const &str);
		static int			checkDate(date const &date);

};

#endif
