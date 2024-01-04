#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>

typedef	struct s_data
{
	int		i;
	char	c;
	float	f;
	double	d;
}	Data;

class	Serializer
{
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
		
	private:
		Serializer();
		Serializer(Serializer const &cpy);
		~Serializer();
		Serializer	&operator=(Serializer const &cpy);
};
#endif
