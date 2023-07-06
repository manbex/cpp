#ifndef __CHARACTER_H__
# define __CHARACTER_H__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>
#include <iostream>

class	Character: public ICharacter
{
	public:
		Character();
		Character(Character const &);
		Character(std::string const &);
		virtual ~Character();
		Character	&operator=(Character const &);

		virtual std::string const	&getName() const;

		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
		
	private:
		std::string		_name;
		AMateria		*_inventory[4];
};

#endif
