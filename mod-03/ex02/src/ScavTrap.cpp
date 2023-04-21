/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:23:47 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 15:23:49 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 50;
	_attack = 20;
	std::cout << "ScavTrap: " << name << " was constructed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(!_health)
	{
		std::cout << "ScavTrap: " << _name << " is dieded, can not attack!" << std::endl;
		return ;
	}
	if(!_energy)
	{
		std::cout << "ScavTrap: " << _name << " is tired, can not attack!" << std::endl;
		return ;
	}
		std::cout << "ScavTrap: " << _name << " attacks " << target << " causing " << _attack << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << _name << " is now in Gatekeeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << _name << " was destroyed" << std::endl;
}