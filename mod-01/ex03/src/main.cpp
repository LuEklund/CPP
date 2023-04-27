/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:27:45 by leklund           #+#    #+#             */
/*   Updated: 2023/04/14 12:27:46 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "HumanA.hpp"
# include "HumanB.hpp"
# include <iostream>

int	main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	// Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	// jim.setWeapon(club);x
	jim.attack();
	// club.setType("some other type of club");
	// jim.attack();
	}

	return (0);
}
