/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:16:52 by leklund           #+#    #+#             */
/*   Updated: 2023/04/24 10:16:53 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria(std::string const &type)
{
	std::cout << "AMateria class was constructed and type=" << type << std::endl;
	_type = type;
}

AMateria::AMateria(const AMateria& to_copy_from)
{
	*this = to_copy_from;
}

AMateria& AMateria::operator=(const AMateria& other) 
{
	if(this == &other)
		return(*this);
	_type = other._type;
	return(*this);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Default use on" << target.getName() << std::endl;
}

std::string const& AMateria::getType() const
{
	return(_type);
}

AMateria::~AMateria()
{
	std::cout << "AMateria class was Destroyed" << std::endl;

}
