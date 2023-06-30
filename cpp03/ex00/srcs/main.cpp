#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	test("Clap");

	std::cout << std::endl;
	test.info();
	test.takeDamage(9);
	test.info();
	test.beRepaired(6);
	test.info();
	std::cout << std::endl;

	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.attack("Enemy");
	test.info();
	test.attack("Enemy");
	test.beRepaired(6);
	std::cout << std::endl;

	test.takeDamage(10);
	test.info();
	test.attack("Enemy");
	test.beRepaired(6);
	std::cout << std::endl;

	return (0);
}
