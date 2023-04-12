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
// #include "Contact.hpp"
// #include "PhoneBook.hpp"
#include <iostream>

int main()
{
	// PhoneBook phonebook;
	// Contact contacts;

	char buf[4096];

	while(42)
	{
		std::cout << "PhoneBook: use ADD SEARCH or EXIT\n";
		if(!(std::cin >> buf))
		{
			std::cout << "Great you broke it >:(\n";
			break ;
		}
		std::cout << "your string[" << buf << "]\n";
		std::cout << "ADD[" << strncmp(buf, "ADD", 4) << "]\n";
		std::cout << "ADD[" << strncmp(buf, "SEARCH", 7) << "]\n";
		std::cout << "ADD[" << strncmp(buf, "EXIT", 5) << "]\n";
		if(strlen(buf) >= 7 || !(!strncmp(buf, "ADD", 4) || !strncmp(buf, "SEARCH", 7) || !strncmp(buf, "EXIT", 5)))
			{
				std::cout << "ERROR\nERROR\nERROR\n";
			}
	}
	return (0);
}