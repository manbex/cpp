#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "btc: program must take exactly 1 argument" << std::endl;
		return (1);
	}
	static_cast<void>(argv);
	return (0);
}
