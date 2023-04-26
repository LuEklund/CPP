/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ContactClass.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 06:13:02 by leklund           #+#    #+#             */
/*   Updated: 2023/04/12 06:13:04 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

int	Contact::update(std::string &fName,
					std::string &lName,
					std::string &Nname,
					std::string &Number,
					std::string &Secret)
{
	this->lName = lName;
	this->fName = fName;
	this->Nname = Nname;
	this->Number = Number;
	this->Secret = Secret;
	return (0);
}

int	putField(std::string &Field)
{
	if (Field.length() > 10)
		std::cout << std::setw(10) << std::right << Field.substr(0, 9) + "." << " | ";
	else
		std::cout << std::setw(10) << std::right << Field.substr(0, 10) << " | ";
	return (0);
}

int	Contact::displayFull()
{
	std::cout << "First Name: " << this->fName << "\n";
	std::cout << "Last Name: " << this->lName << "\n";
	std::cout << "Nick Name: " << this->Nname << "\n";
	std::cout << "PhoneNumber: " << this->Number << "\n";
	std::cout << "Darkest Secret: " << this->Secret << "\n";
	return (0);
}

int	Contact::displayInfo()
{
	putField(this->fName);
	putField(this->lName);
	putField(this->Nname);
	std::cout << "\n";
	return (0);
}
