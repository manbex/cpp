#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	test("Test");

	test.info();
	test.ClapTrap::info();
	test.attack("Target");
	test.whoAmI();
	return (0);
}
