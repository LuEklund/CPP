/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:35 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 14:40:36 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack(0)
{
	std::cout << name << " was constructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(_energy <= 0)
		return ;
	_energy--;
	std::cout << "ClapTrap: " << _name << " attacks " << target << " causing " << _attack << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_health--;
	std::cout << "ClapTrap: " << _name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_energy <= 0)
		return ;
	_energy--;
	std::cout << "ClapTrap: " << _name << " repairs them self " << amount << " points!" << std::endl;	
}

ClapTrap::~ClapTrap()
{
	std::cout << _name << " was destroyed" << std::endl;
}
