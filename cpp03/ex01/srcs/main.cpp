#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	test("Test");

	std::cout << std::endl;	
	test.info();
	test.takeDamage(50);
	test.info();
	test.beRepaired(35);
	test.info();
	std::cout << std::endl;	

	test.attack("Target");
	test.guardGate();
	test.info();
	std::cout << std::endl;	

	return (0);
}
