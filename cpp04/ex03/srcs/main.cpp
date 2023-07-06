#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	Character *dummy = new Character("Dummy");
	AMateria	*m1 = new Ice();
	AMateria	*m2 = new Cure();
	AMateria	*m3 = m1->clone();
	AMateria	*m4 = m2->clone();
	std::cout << std::endl;

	m1->use(*dummy);
	m2->use(*dummy);
	m3->use(*dummy);
	m4->use(*dummy);
	std::cout << std::endl;

	delete m1;
	m1 = NULL;
	IMateriaSource	*source = new MateriaSource();
	std::cout << std::endl;
	
	source->learnMateria(m1);
	source->learnMateria(m2);
	source->learnMateria(m3);
	source->learnMateria(m4);
	source->learnMateria(m2);
	source->learnMateria(m3);
	std::cout << std::endl;

	m2 = NULL;
	m3 = NULL;
	m4 = NULL;

	m1 = source->createMateria("");
	m1 = source->createMateria("Ice");
	m2 = source->createMateria("Ice");
	m3 = source->createMateria("Cure");
	m4 = source->createMateria("Cure");
	AMateria	*m5 = source->createMateria("Ice");
	std::cout << std::endl;

	delete source;
	std::cout << std::endl;

	Character	*test = new Character("Test");
	std::cout << std::endl;

	test->use(0, *dummy);
	test->use(1, *dummy);
	test->use(2, *dummy);
	test->use(3, *dummy);
	test->use(199, *dummy);
	std::cout << std::endl;

	test->unequip(0);
	test->unequip(1);
	test->unequip(2);
	test->unequip(3);
	test->unequip(199);
	std::cout << std::endl;

	test->equip(NULL);
	test->equip(m1);
	test->equip(m1);
	test->equip(m2);
	test->equip(m3);
	test->equip(m4);
	test->equip(m5);
	std::cout << std::endl;

	test->use(0, *dummy);
	test->use(1, *dummy);
	test->use(2, *dummy);
	test->use(3, *dummy);
	std::cout << std::endl;

	test->unequip(2);
	dummy->equip(m3);
	test->equip(m5);
	test->use(2, *dummy);
	std::cout << std::endl;

	*test = *dummy;
	std::cout << std::endl;

	delete dummy;
	delete test;
	std::cout << std::endl;
	
	return (0);
}
