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
/*
• Hit points (FragTrap)
• Energy points (ScavTrap)
• Attack damage (FragTrap)
• attack() (Scavtrap)
*/



DiamondTrap::DiamondTrap(std::string name)
{
	ClapTrap(name + "_clap_trap");
	this->_name = name;
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_attack = FragTrap::_attack;
	std::cout << "DiamondTrap-_health: " << _health << " should be " << FragTrap::_health << std::endl;
	std::cout << "DiamondTrap-_energy: " << _energy << " should be " << ScavTrap::_energy << std::endl;
	std::cout << "DiamondTrap-_attack: " << _attack << " should be " << FragTrap::_attack << std::endl;
	std::cout << "DiamondTrap constructor called and variables initialized." << std::endl;
	return ;
}

// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
// {
// 	FragTrap ft("tmp1");
//     ScavTrap st("tmp2");
    
//     _name = name;
//     // _health = ft.getHealth();
//     // _energy = st.getEnergy();
//     _attack = ft._attack;
// 	// _name = name;
// 	// _health = FragTrap::_health;
//     // _energy = ScavTrap::_energy;
//     // _attack = FragTrap::_attack;
// 	// _health = FragTrap::_health; //FT: 100   ST: 100
// 	// _energy = ScavTrap::_energy; //FT: 100   ST: 50
// 	// _attack = FragTrap::getAttack(); //FT: 30    ST: 20
// 	std::cout << "DiamondTrap: " << name << " was constructed" << std::endl;
// 	std::cout << "DiamondTrap-name: " << name << std::endl;
// 	std::cout << "DiamondTrap-_health: " << _health << " should be " << FragTrap::_health << std::endl;
// 	std::cout << "DiamondTrap-_energy: " << _energy << " should be " << ScavTrap::_energy << std::endl;
// 	std::cout << "DiamondTrap-_attack: " << _attack << " should be " << FragTrap::_attack << std::endl;
// }

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << _name << " was destroyed" << std::endl;
}