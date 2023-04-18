/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:16 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:27:18 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "HumanA.hpp"
# include <iostream>

HumanA::HumanA(std::string name, Weapon& wep) : _name(name), _wep(wep){
}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _wep.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA was destroyed" << std::endl;

}
