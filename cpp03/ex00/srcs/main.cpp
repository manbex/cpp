#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	test("Clap");

	test.info();
	test.attack("Target");
	test.takeDamage(9);
	test.beRepaired(5);
	test.info();
	test.takeDamage(9);
	test.attack("Target");
	test.beRepaired(5);
	test.info();
	return (0);
}
