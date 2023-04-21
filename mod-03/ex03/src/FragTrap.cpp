/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:13:06 by leklund           #+#    #+#             */
/*   Updated: 2023/04/21 08:13:07 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "Constructor ScavTrap called initialized." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << "FragTrap: " << name << " was constructed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << _name << " sends out a High Five! :D, Hopefully someone responded..." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " was destroyed" << std::endl;
}