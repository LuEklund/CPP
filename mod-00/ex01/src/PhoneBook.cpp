/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookClass.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 06:13:10 by leklund           #+#    #+#             */
/*   Updated: 2023/04/12 06:13:14 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>


PhoneBook::PhoneBook() : next(0)
{}

PhoneBook::~PhoneBook()
{}

int	addField(std::string &field)
{
	std::cin.ignore(field.length(), '\n');
	if(!(std::getline(std::cin , field)))
		return (1);
	return (0);
}

int	PhoneBook::addContact()
{
	std::string 	fName;
	std::string 	lName;
	std::string 	Nname;
	std::string		Number;
	std::string		Secret;

	std::cout << "you chose ADD:\nPlease enter\nFirst Name: ";
	addField(fName);
	std::cout << "Last Name: ";
	addField(lName);
	std::cout << "Nick Name: ";
	addField(Nname);
	std::cout << "PhoneNumber: ";
	addField(Number);
	std::cout << "Darkest Secret: ";
	addField(Secret);

	if(!(fName.length() && lName.length() && Nname.length() && Number.length() && Secret.length()))
	{
		std::cout << "ADD FAILED\n";
		return (1);
	}
	contacts[next].update(fName, lName, Nname, Number, Secret);
	next++;
	if(next >= 8)
		next = 0;
	std::cout << "ADD SUCCESSFUL\n";
	return (0);
}

int	PhoneBook::display()
{
	int i = 0;
	std::cout << "Index | First Name |  Last Name |   Nickname\n";
	std::cout << "---------------------------------------------+\n";
	while(i < 8)
	{
		std::cout << "  " << i << "   | ";
		contacts[i].displayInfo();
		i++;
	}
	std::cout << "---------------------------------------------+\n";
	return (0);
}

int	PhoneBook::search()
{
	int index;
	display();
	std::cout << "Please enter the index of the contact you want to see: ";
	if(!(std::cin >> index))
		return (1);
	if (index < 0 || index > 7)
	{
		std::cout << "Invalid index\n";
		return (1);
	}
	contacts[index].displayFull();
	return (0);
}


