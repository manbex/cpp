#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	test("Test");
	
	test.info();
	test.takeDamage(2);
	test.beRepaired(2);
	test.attack("Target");
	test.highFivesGuys();
	return (0);
}
