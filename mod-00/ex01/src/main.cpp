/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:33:08 by leklund           #+#    #+#             */
/*   Updated: 2023/04/05 14:33:10 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int main()
{
	PhoneBook phonebook;
	Contact contacts;

	std::string buf;

	std::cout << "PhoneBook: use ADD SEARCH or EXIT" << std::endl;
	while(42)
	{
		if(!(std::getline(std::cin, buf)))
			break ;
		else if (!strncmp(buf.c_str(), "ADD", 4))
			phonebook.addContact();
		else if(!strncmp(buf.c_str(), "SEARCH", 7))
			phonebook.search();
		else if(!strncmp(buf.c_str(), "EXIT", 5))
			break ;
		else if (buf.length() > 0)
			std::cout << "Invalid command\n";

	}
	return (0);
}