/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:40:45 by leklund           #+#    #+#             */
/*   Updated: 2023/04/20 14:40:47 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"


int	main()
{
	// ClapTrap a("coolGuy");
	// a.attack("badGuy");
	// a.takeDamage(3);
	// a.beRepaired(4);

	ScavTrap b("poopi");
	b.attack("badGuy");
	b.attack("badGuy");
	b.attack("badGuy");
	b.takeDamage(3);
	b.takeDamage(3);
	b.beRepaired(4);
	return (0);
}