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

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_health = 100;
	_energy = 100;
	_attack = 30;
	std::cout << "FragTrap: " << name << " was constructed" << std::endl;
}

FragTrap::FragTrap(const FragTrap& to_copy_from) : ClapTrap(to_copy_from._name)
{
	this->_name = to_copy_from._name;
}

FragTrap& FragTrap::operator=(const FragTrap& other) 
{
	if(this == &other)
		return(*this);
	ClapTrap::operator=(other);
	return(*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << _name << " sends out a High Five! :D, Hopefully someone responded..." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " was destroyed" << std::endl;
}