/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:04:57 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 11:04:59 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice class was constructed type=" << _type << std::endl;
}

Ice::Ice(const Ice& to_copy_from)
{
	std::cout << "Ice copy constructed" << std::endl;
	AMateria::operator=(to_copy_from);
}

Ice& Ice::operator=(const Ice& other) 
{
	AMateria::operator=(other);
	return(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

Ice::~Ice()
{
	std::cout << "Ice class was Destroyed" << std::endl;

}