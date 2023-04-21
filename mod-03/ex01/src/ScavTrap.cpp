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


ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap: " << name << " was constructed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if(setEnergy(getEnergy() - 1))
		std::cout << "ScavTrap: " << getName() << " attacks " << target << " causing " << getAttack() << " points of damage!" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	ClapTrap::takeDamage(amount);
}
void ScavTrap::beRepaired(unsigned int amount)
{
	ClapTrap::beRepaired(amount);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: " << getName() << " was destroyed" << std::endl;
}