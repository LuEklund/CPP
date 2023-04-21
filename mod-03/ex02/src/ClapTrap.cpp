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

ClapTrap::ClapTrap(std::string name, unsigned int health, unsigned int energy, unsigned int attack) : _name(name), _health(health), _energy(energy), _attack(attack)
{
	std::cout << "ClapTrap: " << name << " was constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attack(0)
{
	std::cout << "ClapTrap: " << name << " was constructed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(!isWorking())
		return ;
	_energy--;
	std::cout << _name << " attacks " << target << " causing " << _attack << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(!_health)
	{
		std::cout << _name << " is allready dead" << std::endl;
		return ;
	}
	_health--;
	std::cout << _name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!isWorking())
		return ;
	_energy--;
	_health += amount;
	std::cout << _name << " repairs them self " << amount << " points!" << std::endl;	
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << _name << " was destroyed" << std::endl;
}

bool	ClapTrap::isWorking()
{
	if(_health <= 0)
	{
		std::cout << _name << " is dieded" << std::endl;
		return (false);
	}
	if(_energy <= 0)
	{
		std::cout << _name << " is tired" << std::endl;
		return (false);
	}
	return (true);
}

std::string	ClapTrap::getName(void)
{
	return(_name);
}

unsigned int	ClapTrap::getHealth(void)
{
	return(_health);
}

unsigned int	ClapTrap::getEnergy(void)
{
	return(_energy);
}

unsigned int	ClapTrap::getAttack(void)
{
	return(_attack);
}

bool	ClapTrap::setEnergy(int amount)
{
	if(!isWorking() || amount < 0)
		return(false);
	_energy = amount;
	return(true);
}
