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

	//deep copy tests
	Dog	*b = new Dog();
	std::cout << std::endl;

	(*b).setIdea(0, "test idea 1");
	(*b).setIdea(42, "test idea 2");
	(*b).getIdeas();
	std::cout << std::endl;

	Dog	c = Dog(*b);
	c = *b;
	std::cout << std::endl;

	delete b;
	std::cout << std::endl;
	
	c.getIdeas();
	std::cout << std::endl;


	return (0);
}
