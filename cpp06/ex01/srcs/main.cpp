#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data		data;
	Data		*ptr = &data;
	uintptr_t	raw = Serializer::serialize(ptr);
	Data		*ptr2 = Serializer::deserialize(raw);

	std::cout << ptr << std::endl;
	std::cout << ptr2 << std::endl;
	return (0);
}
