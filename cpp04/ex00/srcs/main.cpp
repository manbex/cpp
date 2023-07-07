#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	const Animal* a = new Animal();
	const Animal* b = new Cat();
	const Animal* c = new Dog();
	const WrongAnimal* d = new WrongAnimal();
	const WrongAnimal* e = new WrongCat();
	const WrongCat* f = new WrongCat();
	std::cout << std::endl;

	std::cout << a->getType() << std::endl;
	std::cout << b->getType() << std::endl;
	std::cout << c->getType() << std::endl;
	std::cout << d->getType() << std::endl;
	std::cout << e->getType() << std::endl;
	std::cout << f->getType() << std::endl;

	std::cout << std::endl;
	a->makeSound(); //will output the animal sound
	b->makeSound(); //will output the cat sound
	c->makeSound(); //will output the dog sound
	d->makeSound();
	e->makeSound();
	f->makeSound();
	std::cout << std::endl;

	delete	a;
	delete	b;
	delete	c;
	delete	d;
	delete	e;
	delete	f;
	std::cout << std::endl;

	return (0);
}
