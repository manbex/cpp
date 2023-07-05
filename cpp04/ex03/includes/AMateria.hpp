#ifndef __AMATERIA_H__
# define __AMATERIA_H__

#include "ICharacter.hpp"
#include <string>

class	ICharacter;

class	AMateria
{
	public:
		AMateria();
		AMateria(AMateria const &);
		AMateria(std::string const &);
		virtual ~AMateria();
		AMateria	&operator=(AMateria const &);

		std::string const &getType() const;
		int					isEquipped() const;
		void				equip();
		void				unequip();
	
		virtual AMateria	*clone() const = 0;
		virtual void		use(ICharacter &);
	
	protected:
		std::string		_type;
		int				_equipped;
};

#endif
