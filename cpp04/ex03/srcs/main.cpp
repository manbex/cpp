#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int	main()
{
	ICharacter	*cloud = new Character("Cloud");
	ICharacter	*sephiroth = new Character("Sephiroth");
	AMateria	*m1 = new Ice();
	std::cout << std::endl;

	cloud->equip(m1);
	cloud->equip(m1);
	sephiroth->equip(m1);
	cloud->use(0, *sephiroth);
	cloud->use(1, *sephiroth);
	std::cout << std::endl;
	
	delete cloud;
	delete sephiroth;
	std::cout << std::endl;

	return (0);
}
