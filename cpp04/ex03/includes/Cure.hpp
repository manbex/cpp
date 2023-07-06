#ifndef __CURE_H__
# define __CURE_H__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class	Cure: public AMateria
{
	public:
		Cure();
		Cure(Cure const &);
		virtual	~Cure();
		Cure	&operator=(Cure const &);

		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
