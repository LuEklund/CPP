/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 08:20:02 by leklund           #+#    #+#             */
/*   Updated: 2023/04/23 08:20:04 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << type << " class was constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat& to_copy_from)
{
	*this = to_copy_from;
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
	if(this == &other)
		return(*this);
	type = other.type;
	return(*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was Destroyed" << std::endl;
}
