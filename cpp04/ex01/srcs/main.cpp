#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	Animal	*a[4];

	a[0] = new Dog();
	a[1] = new Dog();
	a[2] = new Cat();
	a[3] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete a[i];
	std::cout << std::endl;

	return (0);
}
