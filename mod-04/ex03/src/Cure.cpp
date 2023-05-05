/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:05:09 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 11:05:11 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure class was constructed" << std::endl;
}

Cure::Cure(const Cure& to_copy_from)
{
	std::cout << "Cure copy constructed" << std::endl;
	AMateria::operator=(to_copy_from);
}

Cure& Cure::operator=(const Cure& other) 
{
	AMateria::operator=(other);
	return(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;

}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

Cure::~Cure()
{
	std::cout << "Cure class was Destroyed" << std::endl;

}
