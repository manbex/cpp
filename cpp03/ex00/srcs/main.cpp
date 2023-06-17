#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	test("Test");

	test.info();
	test.attack("Target");
	test.takeDamage(15);
	test.beRepaired(5);
	test.info();
	return (0);
}
