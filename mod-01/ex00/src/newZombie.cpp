/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leklund <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 20:24:13 by leklund           #+#    #+#             */
/*   Updated: 2023/04/13 20:24:15 by leklund          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
	Zombie * Zombie_Ptr = new Zombie(name);
	return(Zombie_Ptr);
}
