/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:24:56 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 07:24:57 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal class was constructed" << std::endl;
}

Animal::Animal(const Animal& to_copy_from)
{
	*this = to_copy_from;
}

Animal& Animal::operator=(const Animal& other) 
{
	if(this == &other)
		return(*this);
	type = other.type;
	return(*this);
}

std::string Animal::getType() const
{
	return (type);
}


Animal::~Animal()
{
	std::cout << "Animal class was destroyed" << std::endl;

}