#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	//Animal	a;
	Animal	*test = new Dog();
	std::cout << std::endl;

	delete test;
	std::cout << std::endl;

	return (0);
}
