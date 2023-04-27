/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 09:39:22 by mbenicho          #+#    #+#             */
/*   Updated: 2023/04/18 09:39:24 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H__
# define PHONEBOOK_H__

#include <iostream>
# include <string>
# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	_contact[8];

	public:
		int		add();
		int		search() const;
};

#endif
