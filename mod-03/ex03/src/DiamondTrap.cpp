/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:33:02 by leklund           #+#    #+#             */
/*   Updated: 2023/04/21 08:33:03 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
    FragTrap::_health = 100;
    FragTrap::_attack = 30;
    ScavTrap::_energy = 50;
	std::cout << "DiamondTrap: " << name << " was constructed" << std::endl;
	// std::cout << "DiamondTrap-name: " << name << std::endl;
	// std::cout << "DiamondTrap-_health: " << _health << " should be " << "100" << std::endl;
	// std::cout << "DiamondTrap-_energy: " << _energy << " should be " << "50" << std::endl;
	// std::cout << "DiamondTrap-_attack: " << _attack << " should be " << "30" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& to_copy_from) : ClapTrap(to_copy_from._name + "_clap_name"), FragTrap(to_copy_from._name), ScavTrap(to_copy_from._name)
{
	this->_name = to_copy_from._name;
}


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if(this == &other)
		return(*this);
	_name = other._name;
	ClapTrap::operator=(other);
	return(*this);
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is: " << _name << " and my clap name is: " << ClapTrap::_name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << _name << " was destroyed" << std::endl;
}
