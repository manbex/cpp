#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	test("Test");
	
	std::cout << std::endl;
	test.info();
	test.takeDamage(50);
	test.info();
	test.beRepaired(20);
	test.info();
	std::cout << std::endl;

	test.attack("Target");
	test.highFivesGuys();
	test.info();
	std::cout << std::endl;

	return (0);
}
