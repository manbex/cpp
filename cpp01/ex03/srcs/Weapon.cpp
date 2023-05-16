/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:26:40 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/18 12:17:06 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

std::string const	&Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
