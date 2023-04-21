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


FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap: " << name << " was constructed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: " << getName() << " sends out a High Five! :D, Hopefully someone responded..." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << getName() << " was destroyed" << std::endl;
}