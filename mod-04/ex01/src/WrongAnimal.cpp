/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:20:16 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 08:20:18 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal was constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& to_copy_from)
{
	*this = to_copy_from;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) 
{
	if(this == &other)
		return(*this);
	type = other.type;
	return(*this);
}

std::string WrongAnimal::getType() const
{
	return (type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "this is WrongAnimal sound" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was Destroyed" << std::endl;

}