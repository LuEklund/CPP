/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:37:37 by leklund           #+#    #+#             */
/*   Updated: 2023/04/05 14:37:40 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int	display();
	int	next;
public:
	int	addContact();
	int	search();
	PhoneBook();
	~PhoneBook();
};

#endif

