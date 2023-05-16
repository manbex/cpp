/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:32:38 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/22 15:53:05 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
# define __HUMANB_H__

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();

		void	attack() const;
		void	setWeapon(Weapon &weapon);
	
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
