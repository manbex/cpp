#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	test("Test");

	test.attack("Target");
	test.takeDamage(15);
	test.beRepaired(5);
	return (0);
}
