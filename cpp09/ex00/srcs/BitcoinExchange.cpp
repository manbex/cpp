#include "BitcoinExchange.hpp"

std::map<std::string, double>	BitcoinExchange::database;
std::string						BitcoinExchange::max = "0000-00-00";
std::string						BitcoinExchange::min = "9999-99-99";


void		BitcoinExchange::clearDatabase()
{
	BitcoinExchange::database.clear();
	BitcoinExchange::max = "0000-00-00";
	BitcoinExchange::min = "9999-99-99";
}

BitcoinExchange::date	BitcoinExchange::strtodate(std::string const &str)
{
	BitcoinExchange::date	date;
	char					*s = const_cast<char *>(str.c_str());

	date.year = strtol(s, NULL, 10);
	date.month = strtol(s + 5, NULL, 10);
	date.day = strtol(s + 8, NULL, 10);

	return (date);
}

int	BitcoinExchange::checkDateFormat(std::string const &str)
{
	if (str.size() != 10){
		return (0);
	}
	for (int i = 0; i < 10; i++){
		if (((i == 4 || i == 7) && str[i] != '-')
			|| ((i != 4 && i != 7) && !isdigit(str[i]))){
			return (1);
		}
	}
	return (0);
}

int	BitcoinExchange::checkDate(BitcoinExchange::date const &date)
{
	if (date.month < 1 || date.month > 12){
		return (1);
	}
	if (date.day < 1){
		return (1);
	}
	if (date.month == 2 && date.day > 29){
		return (1);
	}
	if (date.month % 2 && date.day > 31){
		return (1);
	}
	if (date.day > 30){
		return (1);
	}
	return (0);
}

int		BitcoinExchange::checkValue(std::string const &str)
{
	char	*s = const_cast<char *>(str.c_str());
	int			i = 0;

	if (s[i] == '-' || s[i] == '+'){
		i++;
	}
	while (s[i] && isdigit(s[i])){
		i++;
	}
	if (s[i] && (s[i] != '.' || s[i + 1] == 0)){
		return (1);
	}
	if (s[i]){
		i++;
	}
	while(s[i] && isdigit(s[i])){
		i++;
	}
	if (s[i] != 0){
		return (1);
	}

	return (0);
}

void	BitcoinExchange::parseData(std::string const &str)
{
	long unsigned int			i = str.find(",");
	if (i == std::string::npos){
		return ;
	}
	std::string const	&tmp1 = str.substr(0, i);
	std::string const	&tmp2 = str.substr(i + 1);

	if (checkDateFormat(tmp1)){
		return ;
	}
	BitcoinExchange::date	date = BitcoinExchange::strtodate(tmp1);
	if (checkDate(date)){
		return ;
	}
	if (checkValue(tmp2)){
		return ;
	}
	double	d = strtod(tmp2.c_str(), NULL);
	if (errno == ERANGE){
		return ;
	}
	if (d < 0){
		return ;
	}

	if (tmp1 > BitcoinExchange::max){
		BitcoinExchange::max = tmp1;
	}
	if (tmp1 < BitcoinExchange::min){
		BitcoinExchange::min = tmp1;
	}

	BitcoinExchange::database.insert(std::map<std::string, double>::value_type(tmp1, d));
}

int			BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream	file;

	file.open(filename.c_str(), std::ios::in);
	if (!file.is_open()){
		std::cerr << "Error:could not open data file" << std::endl;
		return (1);
	}
	std::string		buf;
	getline(file, buf);
	while (getline(file, buf)){
		BitcoinExchange::parseData(buf);
	}
	file.close();
	return (0);
}

void		BitcoinExchange::parseInput(std::string const &str)
{
	long unsigned int	i = str.find(" | ");
	if (i == std::string::npos){
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	std::string const	&tmp1 = str.substr(0, i);
	std::string const	&tmp2 = str.substr(i + 3);

	if (checkDateFormat(tmp1)){
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	BitcoinExchange::date	date = BitcoinExchange::strtodate(tmp1);
	if (checkDate(date)){
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	if (checkValue(tmp2)){
		std::cout << "Error: bad input => " << str << std::endl;
		return ;
	}
	double	d = strtod(tmp2.c_str(), NULL);
	if (errno == ERANGE || d > 1000){
		std::cout << "Error: too large a number" << std::endl;
		return ;
	}
	if (d < 0){
		std::cout << "Error: not a positive number" << std::endl;
		return ;
	}
	if (tmp1 < BitcoinExchange::min){
		std::cout << "Error: no data provided"<< std::endl;
		return ;
	}

	std::map<std::string, double>::iterator	it = BitcoinExchange::database.begin();
	std::map<std::string, double>::iterator	ite = BitcoinExchange::database.end();
	while (it != ite){
		ite--;
		if (!ite->first.compare(tmp1) || ite->first < tmp1){
			break ;
		}
	}
	std::cout << ite->first << " => " << tmp2 << " = " << d * ite->second << std::endl;
}

int			BitcoinExchange::checkInput(char const *filename)
{
	std::ifstream	file;

	file.open(filename, std::ios::in);
	if (!file.is_open()){
		std::cerr << "Error: could not open input file" << std::endl;
		return (1);
	}
	std::string		buf;
	getline(file, buf);
	while (getline(file, buf)){
		BitcoinExchange::parseInput(buf);
	}
	file.close();
	return (0);
}
