/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:04:04 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/18 12:24:52 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H__
# define WEAPON_H__

#include <string>

class	Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();

		std::string const	&getType() const;
		void				setType(std::string type);

	private:
		std::string	_type;
};

#endif
