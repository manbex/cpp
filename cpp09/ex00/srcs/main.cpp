#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cout << "btc: program must take exactly 1 argument" << std::endl;
		return (1);
	}
	static_cast<void>(argv);
	try {
		if (BitcoinExchange::loadDatabase("data.csv")){
			return (1);
		}
		if (BitcoinExchange::checkInput(argv[1])){
			return (1);
		}
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
} 
