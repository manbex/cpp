#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	test("Diamond");

	std::cout << std::endl;
	test.info();
	test.ClapTrap::info();
	test.attack("Target");
	std::cout << std::endl;

	test.guardGate();
	test.highFivesGuys();
	test.whoAmI();
	std::cout << std::endl;

	return (0);
}
