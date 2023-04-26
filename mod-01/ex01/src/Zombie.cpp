/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 08:43:01 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 08:43:03 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << ": was constructed" << std::endl;
	announce();
}
Zombie::Zombie()
{
	std::cout << "A zombie was constructed" << std::endl;
}

void	Zombie::setName(std::string name){
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name << ": was destroyed" << std::endl;
}
