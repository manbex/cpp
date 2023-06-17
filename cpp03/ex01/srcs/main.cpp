#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	test("Test");

	test.info();
	test.attack("Target");
	test.guardGate();
	return (0);
}
