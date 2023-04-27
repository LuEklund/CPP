/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:23 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:27:25 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "HumanB.hpp"
# include <iostream>

HumanB::HumanB(std::string name) : _name(name), _wep(nullptr)
{
	std::cout << name << ": HumanB was constructed" << std::endl;

}

void	HumanB::attack()
{
	if(_wep == nullptr)
	{
		std::cout << _name << " attacks with their nullpointer" << std::endl;
		return ;
	}
	std::cout << _name << " attacks with their " << _wep->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& wep)
{
	this->_wep = &wep;
}

HumanB::~HumanB()
{
	std::cout << "HumanB was destroyed" << std::endl;
}

