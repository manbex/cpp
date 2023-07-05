#ifndef __ICE_H__
# define __ICE_H__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class	Ice: public AMateria
{
	public:
		Ice();
		Ice(Ice const &);
		virtual	~Ice();
		Ice	&operator=(Ice const &);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
