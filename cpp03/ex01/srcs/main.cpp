#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	test("Test");
	
	test.info();
	test.takeDamage(2);
	test.beRepaired(2);
	test.attack("Target");
	test.guardGate();
	return (0);
}
