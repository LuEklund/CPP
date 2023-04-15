/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:59 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:28:00 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"
# include <iostream>

const	std::string Weapon::getType(void)
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(std::string type)
{
	Weapon::setType(type);
}

Weapon::~Weapon()
{
}
