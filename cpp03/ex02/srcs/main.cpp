#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	ScavTrap	test("Test");

	test.info();
	test.attack("Target");
	test.guardGate();
	return (0);
}
